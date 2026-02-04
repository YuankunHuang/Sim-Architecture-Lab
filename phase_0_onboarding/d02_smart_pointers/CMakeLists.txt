include(FetchContent)
FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(fmt)

add_executable(drill_0_2 src/main.cpp)
target_link_libraries(drill_0_2 fmt)