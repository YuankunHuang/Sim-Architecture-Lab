cmake_minimum_required(VERSION 3.15)

# =============================================================================
# Sim-Architecture-Lab
# A 22-week high-performance C++ simulation training program
# =============================================================================

project(SimArchitectureLab VERSION 1.0.0 LANGUAGES CXX)

# -----------------------------------------------------------------------------
# Global Settings
# -----------------------------------------------------------------------------

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Output directories

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

# -----------------------------------------------------------------------------
# Dependencies
# -----------------------------------------------------------------------------

include(FetchContent)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.5
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(raylib)

# -----------------------------------------------------------------------------
# Phase Subdirectories
# Uncomment as you progress through the curriculum
# -----------------------------------------------------------------------------

# Phase 0: C++ Onboarding
add_subdirectory(phase_0_onboarding)

# Phase 1: Memory Architecture
# add_subdirectory(phase_1_memory)

# Phase 2: Data-Oriented Design
# add_subdirectory(phase_2_dod)

# Phase 3: Concurrency
# add_subdirectory(phase_3_concurrency)

# Phase 4: Lock-Free Programming
# add_subdirectory(phase_4_lockfree)

# Phase 5: Network Programming
# add_subdirectory(phase_5_network)

# Phase 6: SIMD Optimization
# add_subdirectory(phase_6_simd)

# Phase 7: Distributed Simulation
# add_subdirectory(phase_7_distributed)

# -----------------------------------------------------------------------------
# Status
# -----------------------------------------------------------------------------

message(STATUS "")
message(STATUS "╔═══════════════════════════════════════════════════════════════╗")
message(STATUS "║           Sim-Architecture-Lab v${PROJECT_VERSION}                      ║")
message(STATUS "║           C++${CMAKE_CXX_STANDARD} | CMake ${CMAKE_VERSION}                             ║")
message(STATUS "╚═══════════════════════════════════════════════════════════════╝")
message(STATUS "")
