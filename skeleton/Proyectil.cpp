#include "Proyectil.h"

Proyectil::Proyectil(Vector3 pos, Vector3 velReal, float mReal, Vector3 gReal) : Particle() , _velReal(velReal) , _mReal(mReal) , _gravReal(gReal)
{
	vSimple = 5.0f;
	_pose = physx::PxTransform(pos);

	//Velocidad simulada
	_vel = _velReal * (1/vSimple);

	_m = toSimulatedMass(_mReal);
	_gravedad = toSimulatedGravity(_gravReal);
}

void Proyectil::ChangeRealMass(float newMass)
{
}

void Proyectil::ChangeGravity(Vector3 newGravity)
{
}

float Proyectil::toSimulatedMass(float mass)
{
	return mass * pow((_velReal.magnitude() / _vel.magnitude()), 2);;
}

Vector3 Proyectil::toSimulatedGravity(Vector3 gravity)
{
	return gravity * pow((_vel.magnitude() / _velReal.magnitude()), 2);
}
