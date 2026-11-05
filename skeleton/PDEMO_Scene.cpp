#include "PDEMO_Scene.h"
void PDEMO_Scene::init()
{
	Vector3D pos(0, 0, 0);
	float radius = 50;
	float mass = 1000;
	
	planetoideEjemplo = new Planetoide(pos, radius, mass);

	Emisor* emisor1 = new Emisor({ radius + 20 , 0,0 }, { 0,1,0 }, 0.1f, 30.0f, 60.0f, 20, Emisor::UNIFORME, Particle::ESFERA, 2.0f);
	Emisor* emisor2 = new Emisor({ -(radius + 20) , 0,0 }, { 0,-1,0 }, 0.1f, 30.0f, 60.0f, 20, Emisor::UNIFORME, Particle::ESFERA, 2.0f);
	
	emisor1->attachGenerator(planetoideEjemplo->getPlanetoideGravedad());
	emisor2->attachGenerator(planetoideEjemplo->getPlanetoideGravedad());

	emisor1->setTargetConeRadius(1.0f);
	emisor2->setTargetConeRadius(1.0f);

	particulasEspaciales = new SistemaParticulas();
	particulasEspaciales->attachEmisor(emisor1);
	particulasEspaciales->attachEmisor(emisor2);

}

void PDEMO_Scene::update(double dt)
{
	particulasEspaciales->update(dt);
}
