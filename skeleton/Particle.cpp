#include "Particle.h"

Particle::Particle() : _pose({0,0,0}) , _vel({0,0,0}) , initialCalc(true) , _gravedad({0,0,0})
{
	_ac = { 3.0f,.0f,.0f };
	damping = .98f;
	renderItem = new RenderItem(CreateShape(physx::PxSphereGeometry(1.0f)), &_pose, Vector4(.0f, 1.0f, .0f, 1.0f));

}

Particle::Particle(Vector3D Pos, Vector3D vel , Vector3D grav , float tVida) : _vel(vel) , initialCalc(true) , _gravedad(grav) , _tVida(tVida)
{
	_pose = physx::PxTransform(Pos);
	_ac = { 3.0f,.0f,.0f };
	damping = .98f;
	renderItem = new RenderItem(CreateShape(physx::PxSphereGeometry(1.0f)) , &_pose, Vector4(.0f , 1.0f , .0f , 1.0f));
}

Particle::~Particle()
{
	if (renderItem != nullptr)
	{
		delete renderItem;
	}
}

void Particle::integrateEuler(double t)
{
	_ac += _gravedad;
	physx::PxTransform previousP = _pose;
	_pose.p = previousP.p + (_vel * t);
	Vector3 previousV = _vel;
	_vel = previousV + (_ac * t);
	_vel = _vel * pow(damping, t);
	
}

void Particle::integrateSemiImplicitEuler(double t)
{
	_ac += _gravedad;
	_vel = _vel + (_ac*t);
	_vel = _vel * pow(damping , t);
	_pose.p = _pose.p + (_vel * t);
}

void Particle::integrateVerlet(double t)
{
	_ac += _gravedad;
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
