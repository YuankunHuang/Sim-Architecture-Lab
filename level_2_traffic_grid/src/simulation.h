#pragma once

#include <cstddef>
#include <cstdlib>
#include <vector>

class Simulation
{
public:
    Simulation(size_t maxVehicle, size_t gridSize);

    void Tick(float dt);
    const std::vector<int>& GetPostionX() const;
    const std::vector<int>& GetPositionY() const;
    const std::vector<int>& GetPrevPostionX() const;
    const std::vector<int>& GetPrevPositionY() const;

private:
    std::vector<int> position_prev_x_;
    std::vector<int> position_prev_y_;
    std::vector<int> position_x_;
    std::vector<int> position_y_;
    std::vector<int> position_next_x_;
    std::vector<int> position_next_y_;
    std::vector<int> position_final_x_;
    std::vector<int> position_final_y_;
    std::vector<int> grid_;

    size_t max_vehicle_;
    size_t grid_size_;

    int GetGridIndex(const int& x, const int& y);
    void GetNextPosition(const int& x, const int& y, const int& targetX, const int& targetY, int& nextX, int& nextY);
};