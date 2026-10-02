#include "Particle.h"

Particle::Particle(Vector3 Pos, Vector3 vel) : vel(vel)
{
	pose = physx::PxTransform(Pos);
	ac = { 1,0,0 };
	renderItem = new RenderItem(CreateShape(physx::PxSphereGeometry(1.0f)) , &pose, Vector4(.0f , 1.0f , .0f , 1.0f));
}

Particle::~Particle()
{
	if(renderItem != nullptr)
		delete renderItem;
}

void Particle::integrate(double t)
{
	vel = vel + (t*ac);
	pose.p = pose.p + (t * vel);
}
