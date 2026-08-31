# VGLX Starter Application

A minimal C++ project that shows how to set up a simple scene in [VGLX](https://www.vglx.org). This template is designed to give you a clean starting point: no extra code, no unnecessary abstractions, just the essentials wired together with CMake.

### Overview

- A basic application that initializes VGLX
- A rotating cube rendered with a simple material
- A clean CMake setup using `find_package(vglx REQUIRED)`

This project is intentionally small. Its purpose is to help you verify your installation, understand the engine’s initialization flow, and give you a place to begin experimenting with your own scenes.

### Getting Started

The starter expects VGLX to be installed on your system. See the [VGLX Installation Guide](https://www.vglx.org/manual/installation) for instructions.

Clone the repository and build the project using CMake:

```bash
# clone the repository
git clone https://github.com/shlomnissan/vglx-starter.git
cd vglx-starter

# create a build directory (recommended)
mkdir build
cd build

# configure the project
# (set CMAKE_PREFIX_PATH if VGLX is installed in a custom location)
cmake .. --config Debug -DCMAKE_PREFIX_PATH=/path/to/vglx

# compile the application
cmake --build . --config Debug
```

On Windows, the VGLX DLL must be located next to the executable. The CMake script included in this template handles copying the DLL automatically.

After a successful build, run the executable. You should see a rotating cube. If the application launches and the cube animates, your VGLX installation is working correctly.

### Troubleshooting

If the application fails to run:
- Ensure VGLX was installed using the official installer
- Verify that `CMAKE_PREFIX_PATH` points to the VGLX install
- On Windows, check that the DLL was copied next to the executable
- Make sure your GPU driver supports OpenGL 4.1 or newer

If you’re still stuck, open an issue in the main VGLX repo and include your OS, compiler, and CMake logs.
