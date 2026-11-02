#include "Emisor.h"

Particle* Emisor::generarParticula()
{
	//Variables a randomizar
	Vector3D randomDir = generateRandomDirectionVector();

	Vector3D g(0, -3.0, 0);
	Particle* p = new Particle(_pos, randomDir * _vel , g, 1.0f);
	return (p);
}

// Métodos para cambiar los atributos del cono imaginario donde genero las particulas
void Emisor::setOriginConeRadius(float r)
{
	_emCono._rOrigen = r;
}

void Emisor::setTargetConeRadius(float r)
{
	_emCono._rObjetivo = r;
}

void Emisor::setTargetConeHeight(float h)
{
	_emCono._hObjetivo = h;
}

Vector3D Emisor::generateRandomDirectionVector()
{

	Vector3D randomOriginPos = generateRandomPositionInRadius(_emCono._rOrigen);
	Vector3D randomObjetivoPos = generateRandomPositionInRadius(_emCono._rObjetivo) + Vector3D(0,_emCono._hObjetivo , 0);

	return (randomObjetivoPos - randomOriginPos).normalize();
}

Vector3D Emisor::generateRandomPositionInRadius(float r)
{
	float randomSin = randomDistribution(-1, 1);
	float randomCos = randomDistribution(-1, 1);

	Vector3 randomPoint(randomCos * r, 0, randomSin * r);
	return randomPoint;
}


float Emisor::randomDistribution(float limInf, float limSup)
{
	std::mt19937 gen(rd());

	float rNum;

	if (_emDistribucion == Distribution::UNIFORME)
	{
		std::uniform_real_distribution<double> dist(limInf, limSup);//LIMITES
		rNum = dist(gen);
	}
	else if (_emDistribucion == Distribution::GAUSSIANA)
	{
		float media = (limSup + limInf) / 2.0f;
		float dT = limSup / 6.0f;
		std::normal_distribution<float> dist(media, limSup); //MEDIANA , DESVIACIÓN TÍPICA
		rNum = dist(gen);

	}
	return rNum;
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
