#pragma once
#include "GeneradorFuerza.h"
class GeneradorGravedad : public GeneradorFuerza
{
private:
	Vector3D _gravedad;
public:
	GeneradorGravedad(Vector3D gravedad) : GeneradorFuerza(), _gravedad(gravedad) {};

	Vector3D calculateForce(Particle* p , float dt) override;
};

