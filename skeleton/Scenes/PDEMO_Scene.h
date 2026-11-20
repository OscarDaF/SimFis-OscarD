#pragma once

#include "Scene.h"
#include "RenderUtils.hpp"
#include <vector>
#include "Vector3D.h"
#include "Particle.h"
#include "Proyectil.h"
#include "SistemaParticulas.h"
#include "Planetoide.h"


class PDEMO_Scene:public Scene
{
public:
    explicit PDEMO_Scene(std::string name) : Scene(std::move(name)) {}

    void init() override;

    void update(double dt) override;

    void keyPress(unsigned char key, const physx::PxTransform& camera) override {
        if (key == 'r' || key == 'R') {

            //m_transform.p = physx::PxVec3(0.0f, 10.0f, 0.0f); // Reset
        }
        particulasEspaciales->keyPress(key, camera);
    }

    void cleanup() override {
        delete particulasEspaciales;
        delete planetoideEjemplo;
    }

private:
    physx::PxTransform m_transform;
    Planetoide* planetoideEjemplo;
    SistemaParticulas* particulasEspaciales;
};

