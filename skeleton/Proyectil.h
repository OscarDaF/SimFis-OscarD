#pragma once

#include "Particle.h"

class Proyectil : public Particle
{
private:
	Vector3 velSim;
	float _mSim;
public:
	Proyectil(Vector3 Pos, Vector3 vel, float m, Vector3 g);

	void ChangeM(float m);
	void ChangeG(Vector3 g);
	
};

