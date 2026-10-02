#include "Particle.h"

Particle::Particle(Vector3 Pos, Vector3 vel) : vel(vel)
{
	pose.p = Pos;
	renderItem = new RenderItem(CreateShape(physx::PxSphereGeometry(1.0f)) , Vector4(.0f , 1.0f , .0f , 1.0f));
}

Particle::~Particle()
{
	if(renderItem != nullptr)
		delete renderItem;
}

void Particle::integrate(double t)
{
	pose.p = pose.p + (t * vel);
}
