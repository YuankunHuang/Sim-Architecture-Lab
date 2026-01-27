cmake_minimum_required(VERSION 3.15)

# Project Name
project(SimulationArchitectQuest VERSION 0.1.0 LANGUAGES CXX)

# ---------------------------------------------------------
# Global Settings
# ---------------------------------------------------------

# C++ 20 Strongly Recommended for Modules & Concepts
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Output Directory: Move all .exe into bin/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

# ---------------------------------------------------------
# Quest Levels
# ---------------------------------------------------------

# "Unlock" one line at a time
# add_subdirectory(shared)
# add_subdirectory(level_1_particle_storm)
# add_subdirectory(level_2_traffic_grid)

message(STATUS "🚀 Simulation Architect Quest initialized using C++ ${CMAKE_CXX_STANDARD}")