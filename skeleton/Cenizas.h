#pragma once
#include "Emisor.h"
class Cenizas : public Emisor
{
public:
	Cenizas(Vector3D pos, Vector3D dir, float tV , Vector4 col1 , Vector4 col2):
		Emisor(pos , dir , 0.01f , 20 , tV , 0.1f , GAUSSIANA , Particle::CUBO , 0.5f , col1 , {0,0,0} , true , false) 
	{
		setSecColor(col2);
		setTargetConeRadius(1.0f);
	}
};

