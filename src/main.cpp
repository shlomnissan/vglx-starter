/*
===========================================================================
  VGLX https://vglx.org
  Copyright © 2024 - Present, Shlomi Nissan
===========================================================================
*/

#include <vglx/vglx.hpp>

#include "scene.hpp"

struct App : public vglx::Application {
    auto Configure() ->  App::Parameters override {
        return {
            .title = "VGLX Starter",
            .clear_color = {0x000000},
            .width = 1024,
            .height = 768,
            .antialiasing = 4,
            .vsync = false,
            .show_stats = true,
        };
    }

    auto CreateScene() -> std::unique_ptr<vglx::Scene> override {
        return std::make_unique<Scene>();
    }

    auto Update([[maybe_unused]] float delta) -> bool override {
        return true;
    }
};

auto main() -> int {
    App().Start();

    return 0;
}