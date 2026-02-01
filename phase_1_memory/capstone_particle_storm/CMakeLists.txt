add_executable(P1_ParticleStorm 
    src/main.cpp
    src/particle_system.cpp
)

target_include_directories(P1_ParticleStorm PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(P1_ParticleStorm PRIVATE raylib)

# Compiler optimizations for release
target_compile_options(P1_ParticleStorm PRIVATE
    $<$<CONFIG:Release>:-O3 -march=native>
)
