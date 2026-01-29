add_executable(L2_TrafficGrid
    src/main.cpp
    src/simulation.cpp
)

target_include_directories(L2_TrafficGrid PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(L2_TrafficGrid PRIVATE raylib)