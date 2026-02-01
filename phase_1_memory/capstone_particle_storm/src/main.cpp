#include "particle_system.h"
#include "raylib.h"
#include "rlgl.h"

constexpr int kScreenWidth = 1280;
constexpr int kScreenHeight = 920;
constexpr size_t kMaxParticles = 100000;
constexpr int kTargetFps = 60;
constexpr size_t kEmittedPerFrame = 500;
constexpr int kMinLifetime = 10;
constexpr int kMaxLifetime = 20;

int main()
{
    InitWindow(kScreenWidth, kScreenHeight, "Capstone 1: Particle Storm");
    SetTargetFPS(kTargetFps);

    ParticleSystem particles(kMaxParticles);

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        particles.update(dt);

        // emit
        for (size_t i = 0; i < kEmittedPerFrame; ++i)
        {
            float vx = GetRandomValue(-100, 100);
            float vy = GetRandomValue(-100, 100);
            float lifetime = GetRandomValue(kMinLifetime, kMaxLifetime);
            particles.spawn(kScreenWidth / 2.0f, 0, vx, vy, lifetime);
        }

        // render
        BeginDrawing();
        ClearBackground(BLACK);

        const float* positions_x = particles.get_positions_x();
        const float* positions_y = particles.get_positions_y();
        const float size = 1.0f;

        rlBegin(RL_QUADS);
        for (size_t i = 0; i < particles.get_active_count(); ++i)
        {
            float x = positions_x[i];
            float y = positions_y[i];
            
            rlColor4ub(255, 255, 255, 255);
            rlVertex2f(x - size, y - size);
            rlVertex2f(x - size, y + size);
            rlVertex2f(x + size, y + size);
            rlVertex2f(x + size, y - size);
        }
        rlEnd();

        DrawFPS(10, 10);
        DrawText(TextFormat("Particles: %zu", particles.get_active_count()), 10, 40, 20, GREEN);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
