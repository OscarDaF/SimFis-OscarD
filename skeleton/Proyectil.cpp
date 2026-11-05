#include "Proyectil.h"

Proyectil::Proyectil(Vector3D pos, Vector3D velReal, float mReal, Vector3D gReal) : Particle() , _velReal(velReal) , _mReal(mReal) , _gravReal(gReal)
{
	_pose = physx::PxTransform(pos);

	//Velocidad simulada
	_vel = _velReal * (1/vSimple);

	_w = 1 / toSimulatedMass(_mReal);
	_gravedad = toSimulatedGravity(_gravReal);
}

Proyectil::Proyectil(Vector3D Pos, Vector3D velReal, float mReal, Vector3D gReal, float tVida, FORMA shape, float size, Vector4 color, bool redSize):
	Particle(Pos , (velReal * (1 / vSimple)) , toSimulatedGravity(gReal) , toSimulatedMass(mReal), tVida, shape, size, color, redSize),
	_velReal(velReal),
	_mReal(mReal),
	_gravReal(gReal)
{
	_w = 1 / toSimulatedMass(_mReal);
}

void Proyectil::ChangeRealMass(float newMass)
{
	_mReal = newMass;
	_m = toSimulatedMass(_mReal);
}

void Proyectil::ChangeGravity(Vector3D newGravity)
{
	_gravReal = newGravity;
	_gravedad = toSimulatedGravity(_gravReal);
}

float Proyectil::toSimulatedMass(float mass)
{
	return mass * pow((_velReal.magnitude() / _vel.magnitude()), 2);;
}

Vector3D Proyectil::toSimulatedGravity(Vector3D gravity)
{
	return gravity * pow((_vel.magnitude() / _velReal.magnitude()), 2);
}
