#pragma once

#include "Vector3D.h"
#include "RenderUtils.hpp"

class Particle
{
protected:

	Vector3D _vel;
	Vector3D _ac;
	Vector3D _gravedad;
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
	Particle(Vector3D Pos , Vector3D vel , Vector3D grav , float tVida);
	~Particle();

	//MÉTODOS DE INTEGRACIÓN
	void integrateEuler(double t);
	void integrateSemiImplicitEuler(double t);
	void integrateVerlet(double t);
	void update(float dt);
	
	// 
	float getTiempoDeVida() { return _tVida; }

};

