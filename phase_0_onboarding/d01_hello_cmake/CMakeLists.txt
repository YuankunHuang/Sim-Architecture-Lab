# Libraries
add_library(greeter STATIC lib/greeter.cpp)
target_include_directories(greeter PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib)

# FetchContent
include(FetchContent)
FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(fmt)

# Executable & Link
add_executable(drill_0_1 src/main.cpp)
target_link_libraries(drill_0_1 PRIVATE greeter raylib fmt::fmt)