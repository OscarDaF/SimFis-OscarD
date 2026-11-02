#include "Proyectil.h"

Proyectil::Proyectil(Vector3D pos, Vector3D velReal, float mReal, Vector3D gReal) : Particle() , _velReal(velReal) , _mReal(mReal) , _gravReal(gReal)
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

void Proyectil::ChangeGravity(Vector3D newGravity)
{
}

float Proyectil::toSimulatedMass(float mass)
{
	return mass * pow((_velReal.magnitude() / _vel.magnitude()), 2);;
}

Vector3D Proyectil::toSimulatedGravity(Vector3D gravity)
{
	return gravity * pow((_vel.magnitude() / _velReal.magnitude()), 2);
}
