#include "GeneradorGravedad.h"
#include "Particle.h"

Vector3D GeneradorGravedad::calculateForce(Particle* p)
{
	return _gravedad;
}
