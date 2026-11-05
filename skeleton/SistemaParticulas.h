#pragma once

#include <vector>
#include <unordered_map>

#include "Vector3D.h"

#include "Particle.h"
#include "GeneradorFuerza.h"

#include "Emisor.h"

class SistemaParticulas
{
private:
	Vector3D pos;
	std::vector<Particle*> _particulas;
	std::vector<Emisor*> _emisores;
public:

	SistemaParticulas();
	~SistemaParticulas();

	void attachEmisor(Emisor* copiaEmisor);
	void update(float dt);
	
};

