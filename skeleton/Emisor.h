#pragma once

#include "Vector3D.h"
#include <random>
#include "Particle.h"
#include <iostream>

class Emisor
{
public:
	enum Distribution
	{
		UNIFORME,
		GAUSSIANA
	};
private:

	std::mt19937 rd;
	
	Vector3D _pos;
	Vector3D _dirEmisión; //Debe estar normalizado para multiplicarlo por la velocidad
	float _tasaGeneracion;
	float _currentTimer = 0;
	float _vel;
	Distribution _emDistribucion;

	struct ConoDistribucion
	{
		float _rOrigen;

		float _rObjetivo;
		float _hObjetivo;
	};
	ConoDistribucion _emCono;

public:
	Emisor();
	Emisor(Vector3D pos, Vector3D dir, float tas, float v , Distribution dist = Distribution::UNIFORME) :
		_pos(pos), _dirEmisión(dir.normalize()), _tasaGeneracion(tas), _vel(v) , _emDistribucion(dist)
	{
	};
	
	void update(float dt);

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

	void setOriginConeRadius(float r);
	void setTargetConeRadius(float r);
	void setTargetConeHeight(float h);


	Vector3D generateRandomDirectionVector(Vector3D position);
	Vector3D generateRandomPositionInRadius(float r);

	float randomDistribution(float limInf , float limSup);
	float distUniforme();
	float distGaussiana();


};

