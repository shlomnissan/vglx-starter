cmake_minimum_required(VERSION 3.25)

project(vglx-starter VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
FetchContent_Declare(
    vglx
    GIT_REPOSITORY https://github.com/shlomnissan/vglx.git
    GIT_TAG v0.4.0
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(vglx)

add_subdirectory(src)
