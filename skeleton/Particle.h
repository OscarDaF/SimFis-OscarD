#pragma once

#include <vector>
#include "Vector3D.h"
#include "RenderUtils.hpp"
#include "GeneradorFuerza.h"

class Particle
{
public:
	enum FORMA
	{
		ESFERA = 1,
		CUBO,
		CAPSULE,
		RANDOM
	};
protected:

	std::vector<GeneradorFuerza*> _FuerzasAplicadas;

	//Atributos base particula
	Vector3D _vel;
	Vector3D _ac;
	Vector3D _gravedad;
	float _m;
	float _w;
	float damping;
	Vector3D _acumuladorF;
	physx::PxTransform _pose;

	//Control de verlet
	bool initialCalc;
	physx::PxTransform lastPoseVerlet;
	
	RenderItem* renderItem;
	
	//Atributos efectos de generadores
	float _tVida;
	float _tVidaAct;
	bool _canReduceSize;
	Vector4 _color;
	Vector4 _secColor;
	FORMA _shape;
	float _size;

public:
	Particle();
	Particle(Vector3D Pos , Vector3D vel , Vector3D grav , float tVida);
	Particle(Vector3D Pos , Vector3D vel , Vector3D grav , float mass, float tVida , FORMA shape, float size, Vector4 color , bool redSize);
	~Particle();

	//MÉTODOS DE INTEGRACIÓN
	void integrateEuler(double t);
	void integrateSemiImplicitEuler(double t);
	void integrateVerlet(double t);
	void attachGeneratorsFromEm(std::vector<GeneradorFuerza*> gens) { _FuerzasAplicadas = gens; };
	void update(float dt);
	void calculateForces(float dt);
	void recalculateAC();
	// 
	float getTiempoDeVida() { return _tVidaAct; }
	Vector3D getPos() { return _pose.p;}
	Vector3D getVel() { return _vel; }
	float getMass() { return _m; }
	void setColor(Vector4 color) { _color = color; }
	void setSecColor(Vector4 color) { _secColor = color; }


private:
	void resize();
	void buildShape(float size);
};

