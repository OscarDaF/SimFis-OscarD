#pragma once
#include "GeneradorFuerza.h"
class GeneradorViento : public GeneradorFuerza
{
protected:
	Vector3D _velViento;
public:
	GeneradorViento(Vector3D vel) : GeneradorFuerza(), _velViento(vel) {};

	Vector3D calculateForce(Particle* p) override;
};

