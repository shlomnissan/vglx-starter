# VGLX Starter Application

A minimal C++ project that shows how to set up a simple scene in [VGLX](https://www.vglx.org). This template is designed to give you a clean starting point: no extra code, no unnecessary abstractions, just the essentials wired together with CMake.

### Overview

- A basic application that initializes VGLX
- A rotating cube rendered with a simple material
- A clean CMake setup that pulls VGLX into the build with `FetchContent`

This project is intentionally small. Its purpose is to help you verify your setup, understand the engine’s initialization flow, and give you a place to begin experimenting with your own scenes.

### Getting Started

You need a C++23 compiler and [CMake](https://cmake.org/) 3.25 or newer. VGLX itself does not need to be installed: the first configure downloads it and builds it as part of this project.

Clone the repository and build the project using CMake:

```bash
# clone the repository
git clone https://github.com/shlomnissan/vglx-starter.git
cd vglx-starter

# configure the project
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug

# compile the application
cmake --build build --config Debug
```

VGLX links statically so no runtime files need to be copied next to the executable. To build against a copy of VGLX you already have installed, see the [VGLX Installation Guide](https://www.vglx.org/manual/installation).

After a successful build, run the executable. You should see a rotating cube. If the application launches and the cube animates, your setup is working correctly.

### Troubleshooting

If you run into problems, please [open an issue on GitHub](https://github.com/shlomnissan/vglx-starter/issues). If possible include:

- Your OS and compiler version
- CMake command you ran
- CMake or compiler logs