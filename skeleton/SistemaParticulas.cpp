#include "SistemaParticulas.h"

void SistemaParticulas::update(float dt)
{
	for (auto& e : _emisores)
	{
		e.update(dt);
	}
	for (auto p : _particulas)
	{

	}
}
