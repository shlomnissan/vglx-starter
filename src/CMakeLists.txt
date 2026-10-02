set(TARGET ${PROJECT_NAME})

add_executable(${TARGET} main.cpp)

target_link_libraries(${TARGET} PRIVATE vglx::vglx)
