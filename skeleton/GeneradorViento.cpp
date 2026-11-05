#include "GeneradorViento.h"
#include "Particle.h"


Vector3D GeneradorViento::calculateForce(Particle* p)
{
    Vector3D f = (_velViento - p->getVel()) * 5;
    return f;
}
