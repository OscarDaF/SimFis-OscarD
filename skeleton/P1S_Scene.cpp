#include "P1S_Scene.h"

void P1S_Scene::init()
{
    g = new GeneradorGravedad({ 0,-10,0 });
}

void P1S_Scene::update(double dt)
{
    // Lógica/Integración del alumno (por ejemplo, movimiento simple)
    //m_transform.p.y -= static_cast<float>(9.8 * dt);
    for (auto& p : vProy)
    {
        p->integrateVerlet(dt);
    }
}
