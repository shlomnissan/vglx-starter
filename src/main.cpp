/*
===========================================================================
  VGLX https://vglx.org
  Copyright © 2024 - Present, Shlomi Nissan
===========================================================================
*/

#include <memory>
#include <print>

#include <vglx/vglx.hpp>

struct Scene : public vglx::Scene {
    vglx::Mesh* cube {nullptr};

    Scene() {
        cube = this->Add(vglx::Mesh::Create(
            vglx::BoxGeometry::Create(),
            vglx::PhongMaterial::Create({0x049EF4})
        ));

        this->Add(vglx::AmbientLight::Create({.intensity = 0.5f}));
        this->Add(vglx::PointLight::Create({
            .intensity = 1.0f,
        }))->transform.Translate({2.0f, 2.5f, 4.0f});
    }

    auto OnUpdate(float dt) -> void override {
        cube->transform.Rotate(vglx::Vector3::X(), dt);
        cube->transform.Rotate(vglx::Vector3::Y(), dt);
    }
};

auto main() -> int {
    auto window = vglx::Window ({
        .title = "VGLX Starter",
        .width = 1280,
        .height = 720,
    });

    if (auto result = window.Initialize(); !result.has_value()) {
        std::println(stderr, "{}", result.error());
        return 1;
    }

    auto renderer = vglx::Renderer({
        .framebuffer_width = window.FramebufferWidth(),
        .framebuffer_height = window.FramebufferHeight(),
        .sample_count = 4,
    });

    if (auto result = renderer.Initialize(); !result.has_value()) {
        std::println(stderr, "{}", result.error());
        return 1;
    }

    auto camera = vglx::PerspectiveCamera::Create({
        .fov = vglx::math::DegToRad(60.0f),
        .aspect = window.AspectRatio(),
        .near = 0.1f,
        .far = 1000.0f
    });

    camera->transform.SetPosition({0.0f, 0.0f, 3.0f});

    window.OnResize([&camera, &renderer](const vglx::ResizeParameters& p) {
        renderer.SetViewport(0, 0, p.framebuffer_width, p.framebuffer_height);
        camera->Resize(p.window_width, p.window_height);
    });

    auto scene = std::make_unique<Scene>();

    auto timer = vglx::FrameTimer {true};

    while (!window.ShouldClose()) {
        window.PollEvents();
        scene->Advance(timer.Tick());
        renderer.Render(scene.get(), camera.get());
        window.SwapBuffers();
    }

    return 0;
}