#include "simulation.h"

Simulation::Simulation(size_t maxVehicle, size_t gridSize)
{
    max_vehicle_ = maxVehicle;
    grid_size_ = gridSize;

    position_x_.resize(max_vehicle_);
    position_y_.resize(max_vehicle_);
    position_next_x_.resize(max_vehicle_);
    position_next_y_.resize(max_vehicle_);
    position_final_x_.resize(max_vehicle_);
    position_final_y_.resize(max_vehicle_);
    position_prev_x_.resize(max_vehicle_);
    position_prev_y_.resize(max_vehicle_);
    grid_.resize(grid_size_ * grid_size_, -1);

    for (size_t i = 0; i < max_vehicle_; ++i)
    {
        position_prev_x_[i] = position_x_[i] = rand() % grid_size_;
        position_prev_y_[i] = position_y_[i] = rand() % grid_size_;
        
        position_final_x_[i] = rand() % grid_size_;
        position_final_y_[i] = rand() % grid_size_;
        
        GetNextPosition(position_x_[i], position_y_[i], position_final_x_[i], position_final_y_[i], position_next_x_[i], position_next_y_[i]);
    }
}

void Simulation::Tick(float dt)
{
    // sync version
    for (size_t i = 0; i < max_vehicle_; ++i)
    {
        int curr_i = GetGridIndex(position_x_[i], position_y_[i]);
        int next_i = GetGridIndex(position_next_x_[i], position_next_y_[i]);

        position_prev_x_[i] = position_x_[i];
        position_prev_y_[i] = position_y_[i];

        if (grid_[next_i] == -1) // unoccupied
        {
            grid_[curr_i] = -1; // leave current
            grid_[next_i] = i; // Occupy next

            position_x_[i] = position_next_x_[i];
            position_y_[i] = position_next_y_[i];

            int nextX, nextY;
            GetNextPosition(position_next_x_[i], position_next_y_[i], position_final_x_[i], position_final_y_[i], nextX, nextY);
            position_next_x_[i] = nextX;
            position_next_y_[i] = nextY;
        }
    }

    for (size_t i = 0; i < max_vehicle_; ++i)
    {
        if (position_x_[i] == position_final_x_[i] && 
            position_y_[i] == position_final_y_[i])
        {
            position_final_x_[i] = rand() % grid_size_;
            position_final_y_[i] = rand() % grid_size_;
        }
    }
}

const std::vector<int>& Simulation::GetPostionX() const
{
    return position_x_;
}

const std::vector<int>& Simulation::GetPositionY() const
{
    return position_y_;
}

const std::vector<int>& Simulation::GetPrevPostionX() const
{
    return position_prev_x_;
}

const std::vector<int>& Simulation::GetPrevPositionY() const
{
    return position_prev_y_;
}

int Simulation::GetGridIndex(const int& x, const int& y)
{
    return x * grid_size_ + y;
}

void Simulation::GetNextPosition(const int& x, const int& y, const int& targetX, const int& targetY, int& nextX, int& nextY)
{
    nextX = x;
    nextY = y;

    if (x < targetX)
    {
        nextX = x + 1;
    }
    else if (x > targetX)
    {
        nextX = x - 1;
    }
    else if (y < targetY)
    {
        nextY = y + 1;
    }
    else if (y > targetY)
    {
        nextY = y - 1;
    }
}