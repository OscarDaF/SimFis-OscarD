#pragma once
#include "Emisor.h"
class Confeti : public Emisor
{
public:
	Confeti(Vector3D pos, Vector3D dir, float tV):
		Emisor(pos , dir.normalize(), 0.02f, 40, tV, 0.5, UNIFORME, Particle::RANDOM, 1.0f, {1,1,1,1}, {0,0,0}, true, true) 
	{
		setOriginConeRadius(0.5f);
		setTargetConeRadius(1.f);
	}
};

