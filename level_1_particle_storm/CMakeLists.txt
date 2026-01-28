add_executable(L1_ParticleStorm 
    src/main.cpp
    src/particle_system.cpp
)

target_include_directories(L1_ParticleStorm PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(L1_ParticleStorm PRIVATE raylib)