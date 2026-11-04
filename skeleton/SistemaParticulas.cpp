#include "SistemaParticulas.h"

SistemaParticulas::SistemaParticulas()
{
}

SistemaParticulas::SistemaParticulas(Vector3 pos, Vector3D dir)
{
	//Emisor emisorBase(pos, .02f, 100 , 0.7 , Emisor::GAUSSIANA , Emisor::FORMA::CUBO);
	//emisorBase.setOriginConeRadius(0.0f);
	//emisorBase.setTargetConeRadius(5.0f);
	//emisorBase.setTargetConeHeight(15.0f);
	//_emisores.push_back(emisorBase);
}

SistemaParticulas::~SistemaParticulas()
{
	for (auto& p : _particulas)
	{
		if (p)
		{
			delete p;
			p = nullptr;
		}
	}
}

void SistemaParticulas::attachEmisor(Emisor copiaEmisor)
{
	_emisores.push_back(copiaEmisor);
}

void SistemaParticulas::update(float dt)
{
	for (auto& e : _emisores)
	{
		e.update(dt);
		if (e.canGenerate())
		{
			//std::cout << "Generando" << std:: endl;
			_particulas.push_back(e.generarParticula());
		}
	}
	for (auto& p : _particulas)
	{
		if (p)
		{
			p->update(dt);
			p->integrateVerlet(dt);
			if (p->getTiempoDeVida() <= 0)
			{
				
				delete p;
				p = nullptr;
			}
		}
	}
}
