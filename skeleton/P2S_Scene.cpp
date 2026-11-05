#include "P2S_Scene.h"
#include "Chimenea.h"
void P2S_Scene::init()
{
	Vector3D pos(0, 0, 0);
	Vector3D dir(0, 1.0f, 0);

	sistema = new SistemaParticulas();
	Chimenea* chimenea = new Chimenea(pos ,dir , 10.0f , 4.0f);
	chimenea->setOriginConeRadius(0.0f);
	chimenea->setTargetConeRadius(1.0f);
	sistema->attachEmisor(chimenea);
}

void P2S_Scene::update(double dt)
{
	sistema->update(dt);
}
