#pragma once

#include "Vector3D.h"
#include "RenderUtils.hpp"

class Particle
{
private:

	Vector3 vel;
	physx::PxTransform pose;
	RenderItem* renderItem;

public:

	Particle(Vector3 Pos , Vector3 vel);
	~Particle();

	void integrate(double t);
};

