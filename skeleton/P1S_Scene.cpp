#include "P1S_Scene.h"

void P1S_Scene::init()
{
    //// Ejemplo: Creación de una esfera usando las utilidades de render existentes
    //physx::PxShape* shape = CreateShape(physx::PxSphereGeometry(2.0f));
    //m_transform = physx::PxTransform(physx::PxVec3(0.0f, 10.0f, 0.0f));

    //// Se registra el RenderItem exactamente como en la plantilla original
    //m_renderItem = new RenderItem(shape, &m_transform, Vector4(1.0f, 0.0f, 0.0f, 1.0f));

    part = new Particle({1.0f,1.0f,1.0f} , {5.0f,.0f,.0f});
    
}

void P1S_Scene::update(double dt)
{
    // Lógica/Integración del alumno (por ejemplo, movimiento simple)
    //m_transform.p.y -= static_cast<float>(9.8 * dt);

    part->integrateVerlet(dt);

}
