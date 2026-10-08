#include "Proyectil.h"

void Proyectil::ChangeM(float m)
{
	_mSim = _mReal * pow((vel.magnitude() / velSim.magnitude()), 2);
}

void Proyectil::ChangeG(Vector3 g)
{
	_g = g;
}
