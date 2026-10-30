#include "SistemaParticulas.h"

void SistemaParticulas::update(float dt)
{
	for (auto& e : _emisores)
	{
		_particulas.push_back(e.generarParticula());
	}
	for (auto& p : _particulas)
	{
		p->integrateVerlet(dt);
	}
}
