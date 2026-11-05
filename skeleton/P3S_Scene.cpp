#include "P3S_Scene.h"
#include "Chimenea.h"
#include "GeneradorViento.h"
#include "GeneradorTorbellino.h"
#include "GeneradorExplosion.h"

void P3S_Scene::init()
{
	Vector3D pos(40, 0, 0);
	Vector3D dir(0, 1.0f, 0);

	sistema = new SistemaParticulas();

	//Chimenea
	/*Chimenea* chimenea = new Chimenea(pos, dir, 6.0f, 10.0f);
	chimenea->setOriginConeRadius(0.0f);
	chimenea->setTargetConeRadius(1.0f);
	GeneradorViento* vientoGen = new GeneradorViento({ 70 , 0 , 0 });
	chimenea->attachGenerator(vientoGen);
	sistema->attachEmisor(chimenea);*/

	//FuentesTorbellino
	Emisor* emisor1 = new Emisor({ 0,0,0 }, { 0,1,0 }, 0.0005f, 40.0f, 10.0f, 5, Emisor::GAUSSIANA, Particle::ESFERA, 1.0f, { 1.0f ,.0f,.0f,1.0f }, { 0,0,0 }, false);
	emisor1->setOriginConeRadius(1.0);
	emisor1->setTargetConeRadius(1.0);
	GeneradorTorbellino* torbellino = new GeneradorTorbellino({ 0,5,0 }, 2);
	GeneradorExplosion* explosion = new GeneradorExplosion({ 0,40,0 }, 3000, 20, 50, 0);
	emisor1->attachGenerator(explosion);

	sistema->attachEmisor(emisor1);
	
}

void P3S_Scene::update(double dt)
{
	sistema->update(dt);
}
