#pragma once
#include "Emisor.h"
class Chimenea: public Emisor
{
public:
	Chimenea(Vector3D pos , Vector3D dir, float steamSize) 
		: 
		Emisor(pos , dir , 0.2f, 10, 10, Emisor::UNIFORME, Particle::ESFERA, steamSize, {1.0f,1.0f ,1.0f ,1.0f}, Vector3D(0, 0, 0), true)
		{ };

};

