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
        vglx::PhongMaterial::Create({.color = 0x049EF4})
    ));

    Add(vglx::AmbientLight::Create({
        .color = 0xFFFFFF,
        .intensity = 0.5f
    }));

    Add(vglx::PointLight::Create({
        .color = 0xFFFFFF,
        .intensity = 1.0f,
    }))->transform.Translate({2.0f, 2.5f, 4.0f});
}

auto Scene::OnUpdate(float delta) -> void {
    cube_->transform.Rotate(vglx::Vector3::Right(), delta);
    cube_->transform.Rotate(vglx::Vector3::Up(), delta);
}