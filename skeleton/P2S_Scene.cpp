#include "P2S_Scene.h"

void P2S_Scene::init()
{
	Vector3D pos(0, 0, 0);
	Vector3D dir(0, 1.0f, 0);

	sistema = new SistemaParticulas(pos, dir);
	Chimenea chimenea(pos ,dir , 4.0f);
	chimenea.setOriginConeRadius(0.0f);
	chimenea.setTargetConeRadius(1.0f);
	sistema->attachEmisor(chimenea);
}

void P2S_Scene::update(double dt)
{
	sistema->update(dt);
}
