#include "simulation.h"
#include "raylib.h"
#include "raymath.h"
#include "rlgl.h"

constexpr size_t kScreenWidth = 1600;
constexpr size_t kScreenHeight = 900;

constexpr size_t kMaxVehicle = 10;
constexpr size_t kGridSize = 10;
constexpr size_t kTickPerSec = 6; // slow sim, to visualize the progress better when testing

constexpr float kGridCellSize = 50.0f;
constexpr float kGridPaddingLeft = 250.0f;
constexpr float kGridPaddingTop = 50.0f;

int main()
{
    Simulation sim(kMaxVehicle, kGridSize);
    
    InitWindow(kScreenWidth, kScreenHeight, TextFormat("Level 2 Traffic Grid"));

    float last_tick_time = 0.0f;

    while (!WindowShouldClose())
    {
        float time = GetTime();
        float sim_dt = 1.0f / kTickPerSec;
        float elapsed_time = time - last_tick_time;

        if (elapsed_time >= sim_dt)
        {
            last_tick_time = time;
            elapsed_time = 0.0f;

            // sim
            sim.Tick(sim_dt);
        }

        // render
        float t = Clamp(elapsed_time / sim_dt, 0, 1);

        BeginDrawing();
        ClearBackground(BLACK);

        // 1. Grid
        for (int i = 0; i < kGridSize; ++i)
        {
            for (int j = 0; j < kGridSize; ++j)
            {
                float topLeftX = kGridPaddingLeft + i * kGridCellSize;
                float topLeftY = kGridPaddingTop + j * kGridCellSize;

                rlColor4ub(255, 255, 255, 255);
                DrawRectangleLines(
                    topLeftX, 
                    topLeftY, 
                    kGridCellSize, 
                    kGridCellSize, 
                    Color(255, 255, 255, 255)
                );
            }
        }

        // 2. Vehicles
        const std::vector<int>& position_x = sim.GetPostionX();
        const std::vector<int>& position_y = sim.GetPositionY();
        const std::vector<int>& position_prev_x = sim.GetPrevPostionX();
        const std::vector<int>& position_prev_y = sim.GetPrevPositionY();
        const float size = kGridCellSize * 0.15f;
        rlBegin(RL_QUADS);
        for (int i = 0; i < kMaxVehicle; ++i)
        {
            float pos_x = kGridPaddingLeft + position_x[i] * kGridCellSize + kGridCellSize / 2;
            float pos_y = kGridPaddingTop + position_y[i] * kGridCellSize + kGridCellSize / 2;
            float prev_pos_x = kGridPaddingLeft + position_prev_x[i] * kGridCellSize + kGridCellSize / 2;
            float prev_pos_y = kGridPaddingTop + position_prev_y[i] * kGridCellSize + kGridCellSize / 2;

            float lerped_pos_x = Lerp(prev_pos_x, pos_x, t);
            float lerped_pos_y = Lerp(prev_pos_y, pos_y, t);

            rlColor4ub(0, 255, 0, 255);
            rlVertex2f(lerped_pos_x - size, lerped_pos_y - size);
            rlVertex2f(lerped_pos_x - size, lerped_pos_y + size);
            rlVertex2f(lerped_pos_x + size, lerped_pos_y + size);
            rlVertex2f(lerped_pos_x + size, lerped_pos_y - size);
        }
        rlEnd();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}