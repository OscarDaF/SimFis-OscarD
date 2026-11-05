#include "GeneradorGravitatorioReal.h"
#include "Particle.h"
Vector3D GeneradorGravitatorioReal::calculateForce(Particle* p, float dt)
{
    Vector3D r = _centro - p->getPos();
    float magnitudFuerza = _cteGU * ((_masaPlanetoide * p->getMass()) / (r.magnitude() * r.magnitude()));

    return r.normalize() * magnitudFuerza;
}
