/*
===========================================================================
  VGLX https://vglx.org
  Copyright © 2024 - Present, Shlomi Nissan
===========================================================================
*/

#include <memory>
#include <print>

#include <vglx/vglx.hpp>

#include "scene.hpp"

constexpr int kSampleCount = 4;

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
        .sample_count = kSampleCount,
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

    camera->TranslateZ(3.0f);

    window.OnResize([&camera, &renderer](const vglx::ResizeParameters& p) {
        renderer.SetViewport(0, 0, p.framebuffer_width, p.framebuffer_height);
        camera->Resize(p.window_width, p.window_height);
    });

    auto my_scene = std::make_unique<Scene>();

    auto timer = vglx::FrameTimer {true};
    while (!window.ShouldClose()) {
        window.PollEvents();
        my_scene->Advance(timer.Tick());
        renderer.Render(my_scene.get(), camera.get());
        window.SwapBuffers();
    }

    return 0;
}