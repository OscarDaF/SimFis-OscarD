#pragma once

#include <vector>
#include <unordered_map>

#include "Vector3D.h"
#include "Particle.h"
#include "Emisor.h"
#include "Chimenea.h"

class SistemaParticulas
{
private:
	Vector3D pos;
	std::vector<Particle*> _particulas;
	
	std::vector<Emisor> _emisores;
public:

	SistemaParticulas();
	SistemaParticulas(Vector3 pos , Vector3D dir);

	~SistemaParticulas();

	void attachEmisor(Emisor copiaEmisor);

	void update(float dt);
	
};

