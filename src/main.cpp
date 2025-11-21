/*
===========================================================================
  VGLX https://vglx.org
  Copyright © 2024 - Present, Shlomi Nissan
===========================================================================
*/

#include <vglx/vglx.hpp>

#include "scene.hpp"

struct Application : public vglx::Application {
    auto Configure() ->  Application::Parameters override {
        return {
            .title = "VGLX Starter",
            .antialiasing = 4,
            .vsync = false,
            .show_stats = true,
        };
    }

    auto CreateScene() -> std::shared_ptr<vglx::Scene> override {
        return std::make_shared<Scene>();
    }

    auto Update([[maybe_unused]] float delta) -> bool override {
        return true;
    }
};

auto main() -> int {
    Application().Start();

    return 0;
}