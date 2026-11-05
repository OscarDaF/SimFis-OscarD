#include "Particle.h"

Particle::Particle() : _pose({0,0,0}) , _vel({0,0,0}) , initialCalc(true) , _gravedad({0,0,0})
{
	_ac = { 0.0f,.0f,.0f };
	damping = .98f;
	renderItem = new RenderItem(CreateShape(physx::PxSphereGeometry(1.0f)), &_pose, Vector4(.0f, 1.0f, .0f, 1.0f));

}

Particle::Particle(Vector3D Pos, Vector3D vel , Vector3D grav , float tVida) : 
	_vel(vel) , initialCalc(true) , _gravedad(grav) , _tVida(tVida) , _tVidaAct(tVida)
{
	_pose = physx::PxTransform(Pos);
	_ac = { 0.0f,.0f,.0f };
	damping = .98f;
	renderItem = new RenderItem(CreateShape(physx::PxSphereGeometry(1.0f)) , &_pose, Vector4(.0f , 1.0f , .0f , 1.0f));
}

Particle::Particle(Vector3D Pos, Vector3D vel, Vector3D grav , float mass, float tVida, FORMA shape , float size , Vector4 color , bool redSize = false)
	: _vel(vel), initialCalc(true), _gravedad(grav), _tVida(tVida) , _m (mass), _shape(shape), _size(size), _color(color), _tVidaAct(tVida), _canReduceSize(redSize)
{
	_pose = physx::PxTransform(Pos);
	_ac = { 0.0f,.0f,.0f };
	damping = .98f;
	_w = 1 / _m;
	buildShape(_size);
}


Particle::~Particle()
{
	if (renderItem != nullptr)
	{
		renderItem->shape->release();
		renderItem->release();
		renderItem = nullptr;
	}
}

void Particle::integrateEuler(double t)
{
	calculateForces(t);
	recalculateAC();
	physx::PxTransform previousP = _pose;
	_pose.p = previousP.p + (_vel * t);
	Vector3 previousV = _vel;
	_vel = previousV + (_ac * t);
	_vel = _vel * pow(damping, t);
}

void Particle::integrateSemiImplicitEuler(double t)
{
	calculateForces(t);
	recalculateAC();
	_vel = _vel + (_ac*t);
	_vel = _vel * pow(damping , t);
	_pose.p = _pose.p + (_vel * t);
}

void Particle::integrateVerlet(double t)
{
	calculateForces(t);
	recalculateAC();
	if (initialCalc)
	{
		lastPoseVerlet = _pose;
		integrateSemiImplicitEuler(t);
	}
	else
	{
		physx::PxTransform previousP = _pose;
		_pose.p = 2 * previousP.p - lastPoseVerlet.p + (_ac * (t * t));
		lastPoseVerlet = previousP;
	}
}

void Particle::update(float dt)
{
	if (_canReduceSize) resize();
	_tVidaAct -= dt;
}

void Particle::calculateForces(float dt)
{
	_acumuladorF = { 0,0,0 };
	for (auto force : _FuerzasAplicadas)
	{
		_acumuladorF += force->calculateForce(this , dt);
	}
}

void Particle::recalculateAC()
{
	_ac = { 0,0,0 };
	_ac += _acumuladorF * _w;
}

void Particle::resize()
{
	if (_tVidaAct > 0)
	{
		renderItem->release();
		float nSize = (_tVidaAct * _size) / _tVida;
		buildShape(nSize);
	}
}

void Particle::buildShape(float size)
{
	physx::PxShape* partShape;
	switch (_shape)
	{
	case Particle::ESFERA:
		partShape = CreateShape(physx::PxSphereGeometry(size));
		break;
	case Particle::CUBO:
		partShape = CreateShape(physx::PxBoxGeometry(size, size, size));
		break;
	case Particle::CAPSULE:
		partShape = CreateShape(physx::PxCapsuleGeometry(size, size));
	default:
		break;
	}
	
	renderItem = new RenderItem(partShape, &_pose, _color);
}
