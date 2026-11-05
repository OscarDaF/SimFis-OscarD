#pragma once
#include "GeneradorFuerza.h"
class GeneradorExplosion : public GeneradorFuerza
{
private:
	
	Vector3D _center;
	float _K;
	float _radioExplosion;
	float _cteTE;
	float _tExplosion;

public:

	GeneradorExplosion(Vector3D cent, float K, float radius, float cteTE, float tInicial) : GeneradorFuerza(),
		_center(cent), _K(K), _radioExplosion(radius), _cteTE(cteTE), _tExplosion(tInicial) {
	};
	Vector3D calculateForce(Particle* p, float dt) override;
	void update(float dt) override;
	void keyPress(unsigned char key, const physx::PxTransform& camera) override
	{
		if (key == 'E' || key == 'e')
		{
			isActive = !isActive;
		}
	}
};

