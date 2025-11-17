find_package(vglx REQUIRED)

set(SOURCE_CODE
    main.cpp
    scene.cpp
    scene.hpp
)

add_executable(vglx-starter ${SOURCE_CODE})

target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<CXX_COMPILER_ID:GNU>:-fno-rtti -fno-exceptions>
    $<$<CXX_COMPILER_ID:Clang>:-fno-rtti -fno-exceptions>
    $<$<CXX_COMPILER_ID:AppleClang>:-fno-rtti -fno-exceptions>
    $<$<CXX_COMPILER_ID:MSVC>:/GR- /EHsc->
)

target_link_libraries(${PROJECT_NAME} PRIVATE vglx::vglx)

if(WIN32)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:vglx::vglx>
    )
endif()