#include "SistemaParticulas.h"
#include <iostream>

SistemaParticulas::SistemaParticulas()
{
}

SistemaParticulas::SistemaParticulas(Vector3 pos, Vector3D dir)
{
	Emisor emisorBase(pos, dir, 5, 10);
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
			std::cout << "Generando" << std:: endl;
			//_particulas.push_back(e.generarParticula());
		}
	}
	for (auto& p : _particulas)
	{
		p->integrateVerlet(dt);
	}
}
