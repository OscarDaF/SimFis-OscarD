#pragma once
#include "GeneradorViento.h"
class GeneradorTorbellino : public GeneradorViento
{
private:
	Vector3D _centro;
	float _K;
public:
	GeneradorTorbellino(Vector3D cent, float k) : GeneradorViento({ 0,0,0 }), _centro(cent), _K(k) {};
	void recalculatedVel(Particle* p);
	Vector3D calculateForce(Particle* p, float dt) override;
};

