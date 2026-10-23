#include "Particle.h"

Particle::Particle() : _pose({0,0,0}) , _vel({0,0,0}) , initialCalc(true) , _gravedad({0,0,0})
{
	_ac = { 3.0f,.0f,.0f };
	damping = .98f;
	renderItem = new RenderItem(CreateShape(physx::PxSphereGeometry(1.0f)), &_pose, Vector4(.0f, 1.0f, .0f, 1.0f));

}

Particle::Particle(Vector3 Pos, Vector3 vel , Vector3 grav , float tVida = 10.0f) : _vel(vel) , initialCalc(true) , _gravedad(grav)
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
	_pose.p = previousP.p + (t * _vel);
	Vector3 previousV = _vel;
	_vel = previousV + (t * _ac);
	_vel = _vel * pow(damping, t);
	
}

void Particle::integrateSemiImplicitEuler(double t)
{
	_ac += _gravedad;
	_vel = _vel + (t*_ac);
	_vel = _vel * pow(damping , t);
	_pose.p = _pose.p + (t * _vel);
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
