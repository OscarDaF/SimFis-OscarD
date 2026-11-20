#pragma once

#include "Particle.h"

class Proyectil : public Particle
{
private:
	Vector3D _velReal;
	Vector3D _gravReal;
	float _mReal;
	float vSimple = 5.0f;
	
public:
	Proyectil(Vector3D pos, Vector3D velReal, float mReal, Vector3D gReal);
	Proyectil(Vector3D Pos, Vector3D velReal, float mReal , Vector3D gReal, float tVida, FORMA shape, float size, Vector4 color, bool redSize);


	void ChangeRealMass(float newMass);
	void ChangeGravity(Vector3D newGravity);

private:
	float toSimulatedMass(float mass);
	Vector3D toSimulatedGravity(Vector3D gravity);
};

