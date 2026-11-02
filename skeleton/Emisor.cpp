#include "Emisor.h"

Particle* Emisor::generarParticula()
{
	//Variables a randomizar
	Vector3D npDir = _dirEmisión * _vel;
	Vector3D a(0, -4.0, 0);

	Particle* p = new Particle(_pos, npDir, a, 10);
	return (p);
}

void Emisor::distUniforme()
{
	std::mt19937 gen (rd());
	std::uniform_int_distribution<> dist(1,6); //LIMITES
}

void Emisor::distGaussiana()
{
	std::mt19937 gen(rd());
	std::normal_distribution<> dist(); //MEDIANA , DESVIACIÓN TÍPICA
}

void Emisor::update(float dt)
{
	_currentTimer += dt;
}
