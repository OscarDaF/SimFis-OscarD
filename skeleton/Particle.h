#pragma once

#include "Vector3D.h"
#include "RenderUtils.hpp"

class Particle
{
private:

	Vector3 vel;
	Vector3 ac;
	float damping;
	physx::PxTransform pose;

	bool initialCalc;
	physx::PxTransform lastPoseVerlet;
	
	RenderItem* renderItem;

public:

	Particle(Vector3 Pos , Vector3 vel);
	~Particle();

	void integrateEuler(double t);
	void integrateSemiImplicitEuler(double t);
	void integrateVerlet(double t);
	
};

