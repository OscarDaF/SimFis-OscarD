#pragma once

#include "Scene.h"
#include "RenderUtils.hpp"
#include <vector>
#include "Vector3D.h"
#include "Particle.h"
#include "Proyectil.h"
#include "GeneradorGravedad.h"
class P1S_Scene : public Scene {
public:
    explicit P1S_Scene(std::string name) : Scene(std::move(name)) {}

    void init() override;

    void update(double dt) override;

    void keyPress(unsigned char key, const physx::PxTransform& camera) override {
        if (key == 'r' || key == 'R') {
            
            //m_transform.p = physx::PxVec3(0.0f, 10.0f, 0.0f); // Reset
        }
        else if (key == ' ')
        {
            Vector3 camPos = GetCamera()->getTransform().p;
            Vector3 camDir = GetCamera()->getDir().getNormalized();
            float vel = 200;
            Proyectil* p = new Proyectil(camPos, camDir * vel, 1, { .0f , 0 , 0.0f } , 10 , Particle::CUBO , 1.0f , {1,1,1,1.0f},false);
            p->addForceGen(g);
            vProy.push_back(p);
        }
        else if (key == 'c' ||key == 'C')
        {
            Vector3 camPos = GetCamera()->getTransform().p;
            Vector3 camDir = GetCamera()->getDir().getNormalized();
            float vel = 30;
            Proyectil* p = new Proyectil(camPos, camDir * vel, 1, { .0f , 0 , 0.0f }, 10, Particle::ESFERA, 1.0f, { 0,1,1,1.0f }, false);
            p->addForceGen(g);
            vProy.push_back(p);
        }
    }

    void cleanup() override {
        if (m_renderItem) {
            m_renderItem->release(); // Deregistra y destruye el item
            m_renderItem = nullptr;
        }

        for (auto& p : vProy)
        {
            delete p;
            p = nullptr;
        }

    }

private:
    physx::PxTransform m_transform;
    RenderItem* m_renderItem{ nullptr };
    GeneradorGravedad* g;
    std::vector<Proyectil*> vProy;
};

