#pragma once

#include <iostream>
#include <random>

#include "Vector3D.h"
#include "Particle.h"
#include "GeneradorFuerza.h"

class Emisor
{
public:
	

	enum Distribution
	{
		UNIFORME,
		GAUSSIANA
	};
protected:

	std::mt19937 rd;
	
	Vector3D _pos;
	Vector3D _dirEmision; //Debe estar normalizado para multiplicarlo por la velocidad
	float _tasaGeneracion;
	float _currentTimer = 0;
	float _vel;
	Distribution _emDistribucion;
	Vector3D _gravity;
	struct ConoDistribucion
	{
		float _rOrigen = .0f;
		float _rObjetivo = .0f;
		float _hObjetivo = 1.0f;
	};
	ConoDistribucion _emCono;
	
	std::vector<GeneradorFuerza*> _emFuerzasAplicadas;

	//ATRIBUTOS PARTICULAS

	float _massPart;
	float _generaltV;
	Particle::FORMA _formaParticulas;
	float _particleSize;
	Vector4 _colorPart;
	bool _canReduceSize;

public:
	Emisor();
	Emisor(Vector3D pos,
		Vector3D _dir,
		float tas, 
		float v,
		float tiempoVidaGen,
		float massP,
		Distribution dist = Distribution::UNIFORME,
		Particle::FORMA formaPart = Particle::ESFERA,
		float size = 1.0f,
		Vector4 color = {1.0f , 1.0f ,1.0f , 1.0f},
		Vector3D grav = Vector3D(0,-10,0),
		bool canReduceSize = false
		):
		_pos(pos), 
		_dirEmision(_dir),
		_tasaGeneracion(tas), 
		_vel(v) , 
		_generaltV(tiempoVidaGen),
		_massPart(massP),
		_emDistribucion(dist), 
		_formaParticulas(formaPart),
		_particleSize(size),
		_colorPart(color),
		_canReduceSize(canReduceSize)
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
	
	//METODOS GENERACIÓN PARTÍCULA
	Particle* generarParticula();

	//ASIGNACION DE GENERADORES DE FUERZAS QUE AFECTARAN A LAS PARTICULAS

	void attachGenerator(GeneradorFuerza* generador) { _emFuerzasAplicadas.push_back(generador); }

	//Metodos para modificar el cono de generación
	void setOriginConeRadius(float r);
	void setTargetConeRadius(float r);
	void setTargetConeHeight(float h);


	Vector3D generateRandomDirectionVector(Vector3D position);
	Vector3D generateRandomPositionInRadius(float r);

	std::pair<Vector3D, Vector3D> generatePosAndDirection();

	//Distrubución random
	float randomDistribution(float limInf , float limSup);
	float distUniforme();
	float distGaussiana();

	//Input
	void keyPress(unsigned char key, const physx::PxTransform& camera) {
		for (auto genf : _emFuerzasAplicadas)
			genf->keyPress(key, camera);
	}

};

