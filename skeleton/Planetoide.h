#pragma once
#include "Vector3D.h"
#include "GeneradorGravitatorioReal.h"
#include "RenderUtils.hpp"

class Planetoide
{
private:
	GeneradorGravitatorioReal* _gravedadPlanetoide;
	physx::PxTransform _pose;
	Vector3D _pos;
	float _radio;
	float _masaPlanetoide;
	RenderItem* renderItem;
public:
	Planetoide(Vector3D posPlaneta, float radio, float masa) : _pos(posPlaneta) , _radio(radio) , _masaPlanetoide(masa)
	{
		_gravedadPlanetoide = new GeneradorGravitatorioReal(_pos , _radio , _masaPlanetoide);
		_pose = physx::PxTransform(_pos);
		renderItem = new RenderItem(CreateShape(physx::PxSphereGeometry(_radio)), &_pose, Vector4(0.4f, 0.2f, 0.1f, 1.0f));

	}
	~Planetoide()
	{
		delete _gravedadPlanetoide;
	}

	GeneradorGravitatorioReal* getPlanetoideGravedad() { return _gravedadPlanetoide; }
};

