#pragma once

#include "Scene.h"
#include "RenderUtils.hpp"
#include <vector>
#include "Vector3D.h"

class P0S_Scene : public Scene {
public:
    explicit P0S_Scene(std::string name) : Scene(std::move(name)) {}

    void init() override {
        // Ejemplo: Creación de una esfera usando las utilidades de render existentes
        physx::PxShape* shape = CreateShape(physx::PxSphereGeometry(1.0f));
        m_transform = physx::PxTransform(physx::PxVec3(0.0f, 0.0f, 0.0f));

        Vector3D D(0.0f, 0.0f, 1.0f);

        Vector3D P_1(2.0f, 0.0f, 3.0f);
        Vector3D P_2(-4.0f, 0.0f, 1.0f);
        Vector3D P_3(2.0f, 0.0f, 5.0f);
        Vector3D P_4(3.0f, 0.0f, 0.0f);

        m_SP1 = physx::PxTransform(P_1);
        m_SP2 = physx::PxTransform(P_2);
        m_SP3 = physx::PxTransform(P_3);
        m_SP4 = physx::PxTransform(P_4);

        float a1 = (acos((D.dot(P_1)) / (D.magnitude() * P_1.magnitude()))) * (180.0 / 3.14f);
        float a2 = (acos((D.dot(P_2)) / (D.magnitude() * P_2.magnitude()))) * (180.0 / 3.14f);
        float a3 = (acos((D.dot(P_3)) / (D.magnitude() * P_3.magnitude()))) * (180.0 / 3.14f);
        float a4 = (acos((D.dot(P_4)) / (D.magnitude() * P_4.magnitude()))) * (180.0 / 3.14f);

        std::cout << a1 << " " << a2 << " " << a3 << " " << a4 << std::endl;

        m_renderItem = new RenderItem(shape , &m_SP1 , physx::PxVec4(0.0f,0.0f,1.0f,1.0f));
        m_renderItem = new RenderItem(shape , &m_SP2 , physx::PxVec4(0.0f,0.0f,1.0f,1.0f));
        m_renderItem = new RenderItem(shape , &m_SP3 , physx::PxVec4(0.0f,0.0f,1.0f,1.0f));
        m_renderItem = new RenderItem(shape , &m_SP4 , physx::PxVec4(0.0f,0.0f,1.0f,1.0f));

    }

    void update(double dt) override {
        // Lógica/Integración del alumno (por ejemplo, movimiento simple)
        //m_transform.p.y -= static_cast<float>(9.8 * dt);
    }

    void keyPress(unsigned char key, const physx::PxTransform& camera) override {
        if (key == 'r' || key == 'R') {
            m_transform.p = physx::PxVec3(0.0f, 10.0f, 0.0f); // Reset
        }
    }

    void cleanup() override {
        if (m_renderItem) {
            m_renderItem->release(); // Deregistra y destruye el item
            m_renderItem = nullptr;
        }
    }

private:
    physx::PxTransform m_transform;
    physx::PxTransform m_SP1;
    physx::PxTransform m_SP2;
    physx::PxTransform m_SP3;
    physx::PxTransform m_SP4;
    
    RenderItem* m_renderItem{ nullptr };
};