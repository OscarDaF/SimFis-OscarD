#pragma once

#include <vector>

#include "Vector3D.h"
#include "Particle.h"
#include "Emisor.h"

class SistemaParticulas
{
private:
	Vector3D pos;
	std::vector<Particle*> _particulas;
	std::vector<Emisor> _emisores;
public:

	SistemaParticulas();
	SistemaParticulas(Vector3 pos);

	void addEmissor();

	void update(float dt);
	
};

