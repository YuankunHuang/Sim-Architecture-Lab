#pragma once

#include <cstddef>
#include <vector>

class ParticleSystem
{
public:
    explicit ParticleSystem(size_t capacity);

    void spawn(float x, float y, float vx, float vy, float lifetime);
    void kill(size_t index);
    void update(float dt);

    const float* get_positions_x() const;
    const float* get_positions_y() const;
    size_t get_active_count() const;

private:
    std::vector<float> position_x_;
    std::vector<float> position_y_;
    std::vector<float> velocity_x_;
    std::vector<float> velocity_y_;
    std::vector<float> lifetime_;

    size_t active_count_ = 0;
    size_t capacity_;
};
