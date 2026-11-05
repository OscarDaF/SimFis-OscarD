#pragma once
#include "Vector3D.h"
class Particle;
class GeneradorFuerza
{
protected:
	bool isActive;
public:
	GeneradorFuerza() { isActive = true; };
	virtual Vector3D calculateForce(Particle* p , float dt) {
		return { 0,0,0 };
	}
	virtual void update(float dt) {};
	virtual void keyPress(unsigned char key, const physx::PxTransform& camera) {
	}
	bool getActive() { return isActive; }
};

