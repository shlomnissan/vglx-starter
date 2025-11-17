/*
===========================================================================
  VGLX https://vglx.org
  Copyright © 2024 - Present, Shlomi Nissan
===========================================================================
*/

#include "scene.hpp"

namespace {

auto cube = vglx::Mesh::Create(
    vglx::BoxGeometry::Create(),
    vglx::PhongMaterial::Create(0x049EF4)
);

}

Scene::Scene() {
    auto ambient_light = vglx::AmbientLight::Create({
        .color = 0xFFFFFF,
        .intensity = .5f
    });

    auto point_light = vglx::PointLight::Create({
        .color = 0xFFFFFF,
        .intensity = 1.0f
    });

    point_light->transform.Translate({2.0f, 2.5f, 4.0f});

    auto dome = vglx::Mesh::Create(
        vglx::SphereGeometry::Create({6.0f}),
        vglx::PhongMaterial::Create(0x000011)
    );

    dome->GetMaterial()->two_sided = true;
    dome->Add(ambient_light);
    dome->Add(point_light);
    dome->Add(cube);

    this->Add(dome);
}

auto Scene::OnAttached(vglx::SharedContextPointer context) -> void {
    this->Add(vglx::OrbitControls::Create(context->camera, {.radius = 3.0f}));
}

auto Scene::OnUpdate(float delta) -> void {
    cube->RotateX(1.0 * delta);
    cube->RotateY(1.0 * delta);
}