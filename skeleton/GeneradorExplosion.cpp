#include "GeneradorExplosion.h"
#include "Particle.h"
#include <cmath>
Vector3D GeneradorExplosion::calculateForce(Particle* p , float dt)
{
    _tExplosion += dt;
    Vector3D vCentroPos = p->getPos() - _center;
    if (vCentroPos.magnitude() < _radioExplosion)
    {
        return vCentroPos * (_K / vCentroPos.magnitude()) * std::exp(_tExplosion / _cteTE);
    }
    else
    {
        return { 0,0,0 };
    }
}
