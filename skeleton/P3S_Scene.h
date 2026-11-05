#pragma once

#include "Scene.h"
#include "RenderUtils.hpp"
#include <vector>
#include "Vector3D.h"
#include "Particle.h"
#include "Proyectil.h"
#include "SistemaParticulas.h"
#include "GeneradorGravedad.h"

class P3S_Scene : public Scene {
public:
    explicit P3S_Scene(std::string name) : Scene(std::move(name)) {}

    void init() override;

    void update(double dt) override;

    void keyPress(unsigned char key, const physx::PxTransform& camera) override {
        if (key == 'r' || key == 'R') {

            //m_transform.p = physx::PxVec3(0.0f, 10.0f, 0.0f); // Reset
        }
    }

    void cleanup() override {

    }

private:
    physx::PxTransform m_transform;
    SistemaParticulas* sistema;
};

