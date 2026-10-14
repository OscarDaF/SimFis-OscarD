#pragma once

#include "Particle.h"

class Proyectil : public Particle
{
private:
	Vector3 _velReal;
	Vector3 _gravReal;
	float _mReal;
	float vSimple;
	
public:
	Proyectil(Vector3 pos, Vector3 velReal, float mReal, Vector3 gReal);


	void ChangeRealMass(float newMass);
	void ChangeGravity(Vector3 newGravity);	

private:
	float toSimulatedMass(float mass);
	Vector3 toSimulatedGravity(Vector3 gravity);
};

