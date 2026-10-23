#pragma once

#include "Vector3D.h"
#include <random>
#include "Particle.h"
class Emisor
{
private:

	std::random_device rd;
	
	Vector3D _pos;
	Vector3D _dirEmisión; //Debe estar normalizado para multiplicarlo por la velocidad
	float _tasaGeneracion;
	float _currentTimer = 0;
	float _vel;
public:
	Emisor();
	Emisor(Vector3D pos , Vector3D dir, float tas, float v);
	
	bool canGenerate()
	{
		if (_currentTimer > _tasaGeneracion)
		{
			_currentTimer = 0;
			return true;
		}
		else return false;
	}
	Particle* generarParticula();

	void distUniforme();
	void distGaussiana();


	void update(float dt);
};

