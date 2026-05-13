/*
===========================================================================
  VGLX https://vglx.org
  Copyright © 2024 - Present, Shlomi Nissan
===========================================================================
*/

#include "scene.hpp"

Scene::Scene() {
    cube_ = Add(vglx::Mesh::Create(
        vglx::BoxGeometry::Create(),
        vglx::PhongMaterial::Create(0x049EF4)
    ));

    Add(vglx::AmbientLight::Create({
        .color = 0xFFFFFF,
        .intensity = .5f
    }));

    Add(vglx::PointLight::Create({
        .color = 0xFFFFFF,
        .intensity = 1.0f,
    }))->transform.Translate({2.0f, 2.5f, 4.0f});
}

auto Scene::OnUpdate(float delta) -> void {
    cube_->RotateX(1.0 * delta);
    cube_->RotateY(1.0 * delta);
}