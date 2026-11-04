#pragma once

#include "Vector3D.h"
#include "RenderUtils.hpp"

class Particle
{
public:
	enum FORMA
	{
		ESFERA,
		CUBO,
		CAPSULE
	};
protected:

	Vector3D _vel;
	Vector3D _ac;
	Vector3D _gravedad;
	float _m;
	float damping;
	float _tVida;
	float _tVidaAct;

	bool _canReduceSize;

	physx::PxTransform _pose;
	
	Vector4 _color;
	
	//Control de verlet
	bool initialCalc;
	physx::PxTransform lastPoseVerlet;
	
	RenderItem* renderItem;
	FORMA _shape;
	float _size;

public:
	Particle();
	Particle(Vector3D Pos , Vector3D vel , Vector3D grav , float tVida);
	Particle(Vector3D Pos , Vector3D vel , Vector3D grav , float tVida , FORMA shape, float size, Vector4 color , bool redSize);
	~Particle();

	//MÉTODOS DE INTEGRACIÓN
	void integrateEuler(double t);
	void integrateSemiImplicitEuler(double t);
	void integrateVerlet(double t);
	void update(float dt);
	
	// 
	float getTiempoDeVida() { return _tVida; }
private:
	void resize();
	void buildShape(float size);
};

