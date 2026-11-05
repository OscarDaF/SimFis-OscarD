#pragma once
#include "GeneradorFuerza.h"
class GeneradorGravitatorioReal : public GeneradorFuerza
{
private:
	Vector3D _centro;
	float _radioPlanetoide;
	float _masaPlanetoide;
	double _cteGU;
public:
	GeneradorGravitatorioReal(Vector3D centro, float radio, float masa) : _centro(centro) , _radioPlanetoide(radio) , _masaPlanetoide(masa) , _cteGU(50.0f) //Temporal
	{}
	virtual Vector3D calculateForce(Particle* p, float dt) override;
	void keyPress(unsigned char key, const physx::PxTransform& camera) {

		if (key == 'E' || key == 'e')
		{
			if (!stateVisitedInCycle)
			{
				isActive = !isActive;
				stateVisitedInCycle = true;
			}
		}
	}
	bool getActive() { return isActive; }
};

