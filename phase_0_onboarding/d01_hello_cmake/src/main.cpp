#include "fmt/format.h"
#include "greeter.h"
#include <fmt/core.h>
#include <iterator>
#include "raylib.h"

constexpr const char* cpp_standard() {
    #if __cplusplus >= 202302L
        return "C++23";
    #elif __cplusplus >= 202002L
        return "C++20";
    #elif __cplusplus >= 201703L
        return "C++17";
    #elif __cplusplus >= 201402L
        return "C++14";
    #elif __cplusplus >= 201103L
        return "C++11";
    #else
        return "Pre-C++11";
    #endif
}
    
int main() {
    Greeter g("MYLOVE");

    fmt::memory_buffer buf;
    
    // greet
    fmt::format_to(std::back_inserter(buf), "{}\n", g.greet());

    // compiler
#if defined (__clang__)
    fmt::format_to(std::back_inserter(buf), "Compiler: Clang\n");
#elif defined (__GNUC__)
    fmt::format_to(std::back_inserter(buf), "Compiler: GCC\n");
#elif defined (_MSC_VER)
    fmt::format_to(std::back_inserter(buf), "Compiler: MSVC\n");
#else
    fmt::format_to(std::back_inserter(buf), "Compiler: Undefined\n");
#endif

    fmt::format_to(std::back_inserter(buf), "C++ Standard: {standard}", fmt::arg("standard", cpp_standard()));

    std::string info = fmt::to_string(buf);

    InitWindow(800, 600, "Drill 01 Hello CMake");

    while (!WindowShouldClose() && GetTime() < 2.0f)
    {
        BeginDrawing();
        ClearBackground(GRAY);
        DrawText(info.c_str(), 150, 150, 20, BLACK);
        EndDrawing();
    }

    CloseWindow();
}