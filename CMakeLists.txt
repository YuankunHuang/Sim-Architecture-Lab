cmake_minimum_required(VERSION 3.15)

# Project Name
project(SimArchitectureLab VERSION 0.1.0 LANGUAGES CXX)

# ---------------------------------------------------------
# Global Settings
# ---------------------------------------------------------

# Export compile commands for IDE IntelliSense
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# C++ 20 Strongly Recommended for Modules & Concepts
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Output Directory: Move all .exe into bin/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

# ---------------------------------------------------------
# Dependencies
# ---------------------------------------------------------

include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.5
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(raylib)

# ---------------------------------------------------------
# Quest Levels
# ---------------------------------------------------------

# "Unlock" one line at a time
# add_subdirectory(shared)
add_subdirectory(level_1_particle_storm)
# add_subdirectory(level_2_traffic_grid)

message(STATUS "🚀 Simulation Architect Quest initialized using C++ ${CMAKE_CXX_STANDARD}")