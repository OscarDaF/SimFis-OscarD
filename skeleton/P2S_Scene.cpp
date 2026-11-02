#include "P2S_Scene.h"

void P2S_Scene::init()
{
	Vector3D pos(0, 0, 0);
	Vector3D dir(0, 1, 0);

	sistema = new SistemaParticulas(pos, dir);
}

void P2S_Scene::update(double dt)
{
	sistema->update(dt);
}
