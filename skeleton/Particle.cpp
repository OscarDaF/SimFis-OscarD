#include "Particle.h"

Particle::Particle(Vector3 Pos, Vector3 ve , float m, Vector3 g) : vel(vel) , initialCalc(true) , _mReal(m) , _g(g)
{
	pose = physx::PxTransform(Pos);
	ac = { 3.0f,.0f,.0f };
	damping = .98f;
	renderItem = new RenderItem(CreateShape(physx::PxSphereGeometry(1.0f)) , &pose, Vector4(.0f , 1.0f , .0f , 1.0f));
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
	physx::PxTransform previousP = pose;
	pose.p = previousP.p + (t * vel);
	Vector3 previousV = vel;
	vel = previousV + (t * ac);
	vel = vel * pow(damping, t);
	
}

void Particle::integrateSemiImplicitEuler(double t)
{
	vel = vel + (t*ac);
	vel = vel * pow(damping , t);
	pose.p = pose.p + (t * vel);
}

void Particle::integrateVerlet(double t)
{
	if (initialCalc)
	{
		lastPoseVerlet = pose;
		integrateSemiImplicitEuler(t);
	}
	else
	{
		physx::PxTransform previousP = pose;
		
		pose.p = 2 * previousP.p - lastPoseVerlet.p + (ac * (t * t));
		lastPoseVerlet = previousP;
	}

}
