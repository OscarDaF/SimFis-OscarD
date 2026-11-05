#include "GeneradorTorbellino.h"
#include "Particle.h"
void GeneradorTorbellino::recalculatedVel(Particle* p)
{
    Vector3D pos = p->getPos();
    
    float vX = -(pos.z - _centro.z);
    float vY = 50 - (pos.y - _centro.y);
    float vZ = pos.x - _centro.x;

    Vector3D vientoNuevo = Vector3D{ vX , vY , vZ } * _K;
    _velViento = vientoNuevo;
}

Vector3D GeneradorTorbellino::calculateForce(Particle* p)
{
    recalculatedVel(p);
    return GeneradorViento::calculateForce(p);
}
