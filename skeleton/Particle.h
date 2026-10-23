#pragma once

#include "Vector3D.h"
#include "RenderUtils.hpp"

class Particle
{
protected:

	Vector3 _vel;
	Vector3 _ac;
	Vector3 _gravedad;
	float _m;
	float damping;
	float _tVida;

	physx::PxTransform _pose;
	
	Vector3 _color;
	
	//Control de verlet
	bool initialCalc;
	physx::PxTransform lastPoseVerlet;
	
	RenderItem* renderItem;

public:
	Particle();
	Particle(Vector3 Pos , Vector3 vel , Vector3 grav , float tVida = 10.0f);
	~Particle();

	//MÉTODOS DE INTEGRACIÓN
	void integrateEuler(double t);
	void integrateSemiImplicitEuler(double t);
	void integrateVerlet(double t);
	
	//
	float getTiempoDeVida() { return _tVida; }

};

