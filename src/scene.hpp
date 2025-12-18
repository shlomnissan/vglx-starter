/*
===========================================================================
  VGLX https://vglx.org
  Copyright © 2024 - Present, Shlomi Nissan
===========================================================================
*/

#pragma once

#include <vglx/vglx.hpp>

class Scene : public vglx::Scene {
public:
    Scene();

    auto OnAttached(vglx::SharedContextPointer context) -> void override;

    auto OnUpdate(float delta) -> void override;

private:
    vglx::Mesh* brick_ {nullptr};
};