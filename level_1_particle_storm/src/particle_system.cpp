#include "particle_system.h"
#include <cstddef>
#include <utility>

ParticleSystem::ParticleSystem(size_t capacity)
{
    capacity_ = capacity;

    position_x_.resize(capacity);
    position_y_.resize(capacity);
    position_z_.resize(capacity);
    velocity_x_.resize(capacity);
    velocity_y_.resize(capacity);
    velocity_z_.resize(capacity);
}

void ParticleSystem::spawn(float x, float y, float z, float vx, float vy, float vz)
{
    if (active_count_ >= capacity_)
    {
        // invalid index
        return;
    }

    position_x_[active_count_] = x;
    position_y_[active_count_] = y;
    position_z_[active_count_] = z;
    velocity_x_[active_count_] = vx;
    velocity_y_[active_count_] = vy;
    velocity_z_[active_count_] = vz;

    ++active_count_;
}

void ParticleSystem::kill(size_t index)
{
    if (active_count_ == 0 || index >= active_count_)
    {
        // invalid index
        return;
    }

    // swap and pop
    size_t last = active_count_ - 1;
    std::swap(position_x_[index], position_x_[last]);
    std::swap(position_y_[index], position_y_[last]);
    std::swap(position_z_[index], position_z_[last]);
    std::swap(velocity_x_[index], velocity_x_[last]);
    std::swap(velocity_y_[index], velocity_y_[last]);
    std::swap(velocity_z_[index], velocity_z_[last]);

    --active_count_;
}

void ParticleSystem::update(float dt)
{
    for (size_t i = 0; i < active_count_; ++i)
    {
        position_x_[i] += velocity_x_[i] * dt;
        position_y_[i] += velocity_y_[i] * dt;
        position_z_[i] += velocity_z_[i] * dt;
    }
}

size_t ParticleSystem::get_active_count() const
{
    return active_count_;
}

const float* ParticleSystem::get_positions_x() const
{
    return position_x_.data();
}

const float* ParticleSystem::get_positions_y() const
{
    return position_y_.data();
}

const float* ParticleSystem::get_positions_z() const
{
    return position_z_.data();
}