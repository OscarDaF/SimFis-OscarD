#pragma once

#include "Vector3D.h"
#include "RenderUtils.hpp"

class Particle
{
protected:

	Vector3 vel;
	Vector3 ac;
	float damping;
	physx::PxTransform pose;

	float _mReal;
	Vector3 _g;

	bool initialCalc;
	physx::PxTransform lastPoseVerlet;
	
	RenderItem* renderItem;

public:

	Particle(Vector3 Pos , Vector3 vel , float m , Vector3 g);
	~Particle();

	void integrateEuler(double t);
	void integrateSemiImplicitEuler(double t);
	void integrateVerlet(double t);
	
};

