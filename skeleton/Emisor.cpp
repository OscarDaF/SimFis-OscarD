#include "Emisor.h"

Particle* Emisor::generarParticula()
{
	//Variables a randomizar
	//Vector3D randomOffset(distUniforme(), distUniforme(), distUniforme());
	Vector3D randomOffset(distGaussiana(), distGaussiana(), distGaussiana());
	Vector3D npDir = (_dirEmisión + randomOffset).normalize() * _vel;
	Vector3D a(0, -5.0, 0);
	Particle* p = new Particle(_pos, npDir, a, 10);
	return (p);
}

float Emisor::distUniforme()
{
	std::mt19937 gen (rd());
	std::uniform_real_distribution<double> dist(-0.5f,0.5f); //LIMITES

	return(dist(gen));
}

float Emisor::distGaussiana()
{
	std::mt19937 gen(rd());
	std::normal_distribution<float> dist(0.0f , 1.0f); //MEDIANA , DESVIACIÓN TÍPICA
	return dist(gen);
}

void Emisor::update(float dt)
{
	_currentTimer += dt;
}
