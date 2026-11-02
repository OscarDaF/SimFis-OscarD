#include "SistemaParticulas.h"

SistemaParticulas::SistemaParticulas()
{
}

SistemaParticulas::SistemaParticulas(Vector3 pos, Vector3D dir)
{
	Emisor emisorBase(pos, dir, .02f, 40);
	emisorBase.setOriginConeRadius(40.0f);
	emisorBase.setTargetConeRadius(.0f);
	emisorBase.setTargetConeHeight(15.0f);
	_emisores.push_back(emisorBase);
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
