#include "particle_system.h"
#include "raylib.h"

// -----------------------------------------------------------------------------
// Constants
// -----------------------------------------------------------------------------

constexpr int kScreenWidth = 1280;
constexpr int kScreenHeight = 720;
constexpr size_t kMaxParticles = 100000;

// -----------------------------------------------------------------------------
// Main
// -----------------------------------------------------------------------------

int main()
{
    // Raylib init
    InitWindow(kScreenWidth, kScreenHeight, "Level 1: Particle Storm");
    SetTargetFPS(60);

    // Particle system init
    ParticleSystem particles(kMaxParticles);

    // Game loop
    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        // === UPDATE ===
        particles.update(dt);

        // === RENDER ===
        BeginDrawing();
        ClearBackground(BLACK);

        // Draw particles
        const float* px = particles.get_positions_x();
        const float* py = particles.get_positions_y();
        size_t count = particles.get_active_count();

        for (size_t i = 0; i < count; ++i)
        {
            DrawPixel(static_cast<int>(px[i]), static_cast<int>(py[i]), WHITE);
        }

        // Debug info
        DrawFPS(10, 10);
        DrawText(TextFormat("Particles: %zu", count), 10, 40, 20, GREEN);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
