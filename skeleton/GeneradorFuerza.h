#pragma once
#include "Vector3D.h"
class Particle;
class GeneradorFuerza
{
protected:
	
public:
	GeneradorFuerza() {};
	virtual Vector3D calculateForce(Particle* p , float dt) {
		return { 0,0,0 };
	}
};

