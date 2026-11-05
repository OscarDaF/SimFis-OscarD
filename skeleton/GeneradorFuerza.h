#pragma once
#include "Vector3D.h"

class GeneradorFuerza
{
protected:
	Vector3D _force;
public:
	GeneradorFuerza() {};
	Vector3D getGeneratorF() { return _force; }
};

