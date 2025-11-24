/*
===========================================================================
  VGLX https://vglx.org
  Copyright © 2024 - Present, Shlomi Nissan
===========================================================================
*/

#include "scene.hpp"

Scene::Scene() {
    brick_ = vglx::Mesh::Create(
        vglx::BoxGeometry::Create(),
        vglx::PhongMaterial::Create(0x049EF4)
    );

    auto ambient_light = vglx::AmbientLight::Create({
        .color = 0xFFFFFF,
        .intensity = .5f
    });

    auto point_light = vglx::PointLight::Create({
        .color = 0xFFFFFF,
        .intensity = 1.0f,
        .attenuation = {
            .base = 1.0f,
            .linear = 0.0f,
            .quadratic = 0.0f
        }
    });

    point_light->transform.Translate({2.0f, 2.5f, 4.0f});

    Add(ambient_light);
    Add(point_light);
    Add(brick_);
}

auto Scene::OnAttached(vglx::SharedContextPointer context) -> void {
    context->camera->TranslateZ(3.0f);
}

auto Scene::OnUpdate(float delta) -> void {
    brick_->RotateX(1.0 * delta);
    brick_->RotateY(1.0 * delta);
}