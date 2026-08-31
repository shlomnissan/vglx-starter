find_package(vglx REQUIRED)

set(TARGET ${PROJECT_NAME})

add_executable(${TARGET} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE vglx::vglx)

if(WIN32)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:vglx::vglx>
        $<TARGET_FILE_DIR:${TARGET}>
    )
endif()