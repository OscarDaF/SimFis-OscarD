#pragma once

#include "Particle.h"

class Proyectil : public Particle
{
private:

public:
	Proyectil(Vector3 Pos, Vector3 vel, float m, Vector3 g);

	void ChangeM();
	void ChangeG();
	
};

