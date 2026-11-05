#include "SistemaParticulas.h"

SistemaParticulas::SistemaParticulas()
{
	generate = true;
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
;
}

void SistemaParticulas::attachEmisor(Emisor* em)
{
	_emisores.push_back(em);
}

void SistemaParticulas::update(float dt)
{
	for (auto& e : _emisores)
	{
		e->update(dt);
		if (e->canGenerate() && generate)
		{
			//std::cout << "Generando" << std:: endl;
			_particulas.push_back(e->generarParticula());
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

void SistemaParticulas::switcGenerator()
{
	generate = !generate;
	std::cout << "Switch " << generate <<  std::endl;
}

