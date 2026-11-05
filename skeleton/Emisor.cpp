#include "Emisor.h"

Particle* Emisor::generarParticula()
{
	//Variables a randomizar

	//Generamos una posición aleatoria dentro del primer radio y otro del segundo
	
	auto posYDir = generatePosAndDirection();

	//Posicion random dentro del primer radio 
	Vector3D randomPos = posYDir.first;
	//Dirección random a partir de la posicion
	Vector3D randomDir = (posYDir.second - posYDir.first).normalize();

	//Velocidad aleatoria
	float randomV = randomDistribution(_vel * (1 - 0.1f), _vel * (1 + 0.1f));

	//TV aleatorio
	float randomTV = randomDistribution(_generaltV * (1 - 0.1f), _generaltV * (1 + 0.1f));

	//Tamaño aleatorio
	float randomSize = randomDistribution(_particleSize * (1 - 0.1f), _particleSize * (1 + 0.1f));
	

	Particle::FORMA forma;
	if (_formaParticulas == Particle::RANDOM)
	{
		forma = randomForma();
	}
	else forma = _formaParticulas;

	Vector4 color;
	if (_randomColor)
	{
		color = { randomDistribution(0,1),randomDistribution(0,1) ,randomDistribution(0,1) , 1.0f };
	}
	else color = _colorPart;

	Particle* p = new Particle(randomPos, randomDir * randomV , _gravity , 3 , randomTV , forma , randomSize, color , _canReduceSize);
	p->setSecColor(_secColorPart);
	p->attachGeneratorsFromEm(_emFuerzasAplicadas);
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

Vector3D Emisor::generateRandomDirectionVector(Vector3D position)
{

	Vector3D randomOriginPos = position;
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

std::pair<Vector3D, Vector3D> Emisor::generatePosAndDirection()
{

	Vector3D centerR1 = _pos;
	Vector3D centerR2 = _pos + (_dirEmision * _emCono._hObjetivo);

	Vector3D auxiliar = (std::abs(_dirEmision.z) < 0.99) ? Vector3D{ 0.0, 0.0, 1.0 } : Vector3D{ 1.0, 0.0, 0.0 };

	Vector3D u = auxiliar.cross(_dirEmision).normalize();
	Vector3D w = _dirEmision.cross(u);

	//Seno y coseno random para los dos circulos
	float randomSinR1 = randomDistribution(-1, 1);
	float randomCosR1 = randomDistribution(-1, 1);

	float randomSinR2 = randomDistribution(-1, 1);
	float randomCosR2 = randomDistribution(-1, 1);

	Vector3D posIni = centerR1 + (u * (randomCosR1 * _emCono._rOrigen)) + (w * (randomSinR1 * _emCono._rOrigen));
	Vector3D pointSecondCircle = centerR2 + (u * (randomCosR2 * _emCono._rObjetivo)) + (w * (randomSinR2 * _emCono._rObjetivo));


	return std::pair<Vector3D, Vector3D>(posIni , pointSecondCircle);
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
		float dT = (limSup - limInf)/ 6.0f;
		std::normal_distribution<float> dist(media, dT); //MEDIANA , DESVIACIÓN TÍPICA
		rNum = dist(gen);

	}
	return rNum;
}

Particle::FORMA Emisor::randomForma()
{
	std::mt19937 gen(rd());

	std::uniform_int_distribution<> dist(Particle::ESFERA, Particle::RANDOM -1);//LIMITES
	return static_cast<Particle::FORMA>( dist(gen));
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
	for (auto f : _emFuerzasAplicadas)
		f->update(dt);
}
