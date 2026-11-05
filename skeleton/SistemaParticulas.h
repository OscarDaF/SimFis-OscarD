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

	bool generate;
public:

	SistemaParticulas();
	~SistemaParticulas();

	void attachEmisor(Emisor* copiaEmisor);
	void update(float dt);
	void switcGenerator();

	void keyPress(unsigned char key, const physx::PxTransform& camera) {
		if (key == 'o')
		{
			switcGenerator();
		}
		for (auto em : _emisores)
			em->keyPress(key, camera);
	}
};

