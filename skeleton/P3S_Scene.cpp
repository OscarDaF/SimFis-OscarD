#include "P3S_Scene.h"
#include "Chimenea.h"
#include "Confeti.h"
#include "Cenizas.h"

#include "GeneradorViento.h"
#include "GeneradorTorbellino.h"
#include "GeneradorExplosion.h"

void P3S_Scene::init()
{
	Vector3D pos(40, 0, 0);
	Vector3D dir(0, 1.0f, 0);

	sistema = new SistemaParticulas();
	//Gravedad
	
	GeneradorGravedad* gravedad = new GeneradorGravedad({0,-9.8f,0});

	//Chimenea
	Chimenea* chimenea = new Chimenea(pos, dir, 6.0f, 10.0f);
	chimenea->setOriginConeRadius(0.0f);
	chimenea->setTargetConeRadius(1.0f);
	GeneradorViento* vientoGen = new GeneradorViento({ 70 , 0 , 0 });
	chimenea->attachGenerator(vientoGen);
	chimenea->attachGenerator(gravedad);
	//sistema->attachEmisor(chimenea);

	//TorbellinoConfeti
	Confeti* confeti = new Confeti({ 20,0,0 }, { -1,1,0 }, 8.0f);
	Confeti* confeti2 = new Confeti({ -20,0,0 }, { 1,1,0 }, 8.0f);
	GeneradorTorbellino* torbellino = new GeneradorTorbellino({ 0,5,0 }, 2);

	confeti->attachGenerator(torbellino);
	confeti->attachGenerator(gravedad);
	confeti2->attachGenerator(torbellino);
	confeti2->attachGenerator(gravedad);

	sistema->attachEmisor(confeti);
	sistema->attachEmisor(confeti2);
	
	//Explosion ceniza
	
	Cenizas* ceniza = new Cenizas({ -50,0,0 }, { 0,1,0 }, 3.0f, { 0.7f , 0.2f , .0f , 1.0f }, { 0.2f,0.2f, 0.2f, 1.0f });
	GeneradorExplosion* explosion = new GeneradorExplosion({ -50,40,0 }, 50000, 30, 4, 0);
	ceniza->attachGenerator(explosion);
	ceniza->attachGenerator(gravedad);
	//sistema->attachEmisor(ceniza);
}

void P3S_Scene::update(double dt)
{
	sistema->update(dt);
}
