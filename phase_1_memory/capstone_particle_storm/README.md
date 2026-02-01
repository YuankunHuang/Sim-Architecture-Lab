# Capstone 1: Particle Storm

High-performance CPU particle system demonstrating memory architecture principles.

![Demo](assets/Level_1.gif)

## Performance Targets

| Metric | Target | Achieved |
|:-------|:-------|:---------|
| Particles | 100,000 | ✅ |
| Frame Rate | 60 FPS | ✅ |
| Runtime Allocation | Zero | ✅ |

## Technical Highlights

### 1. SOA Data Layout

```cpp
// Instead of: Particle particles[N] (AOS)
// We use: separate arrays (SOA)
std::vector<float> position_x_;
std::vector<float> position_y_;
std::vector<float> velocity_x_;
std::vector<float> velocity_y_;
```

**Why:** Cache-friendly, SIMD-optimizable, only load what you need.

### 2. Swap-and-Pop Lifecycle

```cpp
void kill(size_t index) {
    size_t last = active_count_ - 1;
    std::swap(data[index], data[last]);
    --active_count_;
}
```

**Why:** O(1) removal, no holes, branch-free update loop.

### 3. Pre-allocated Pool

```cpp
ParticleSystem(size_t capacity) {
    position_x_.resize(capacity);
    // ... all arrays pre-sized
}
```

**Why:** Zero runtime allocation, predictable memory usage.

### 4. Batch Rendering

| Method | Draw Calls | FPS |
|:-------|:-----------|:----|
| `DrawCircle` per particle | 100,000 | 35 |
| `rlgl` batched quads | 1 | 60 |

**Why:** GPU thrives on batches, not individual calls.

## Architecture

```
┌─────────────────────────────────────────────────────┐
│                    Main Loop                        │
├─────────────────────────────────────────────────────┤
│  1. Update (physics)                                │
│     └── For each active particle: pos += vel * dt  │
│     └── Decrement lifetime, kill if <= 0           │
│                                                     │
│  2. Emit (spawn new particles)                      │
│     └── If active_count < capacity: spawn          │
│                                                     │
│  3. Render (visualization)                          │
│     └── Batch all particles into single draw call  │
└─────────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────┐
│              ParticleSystem (SOA)                   │
├─────────────────────────────────────────────────────┤
│  [active particles...    ][unused capacity...]      │
│  ↑ index 0               ↑ active_count             │
└─────────────────────────────────────────────────────┘
```

## Build & Run

```bash
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j$(nproc)
./bin/P1_ParticleStorm
```

## Skills Demonstrated

- [x] SOA (Struct of Arrays) layout
- [x] Zero-allocation hot path
- [x] Swap-and-pop object lifecycle
- [x] Batch rendering optimization
- [x] CMake build system
- [x] Raylib integration

## Future Improvements (Phase 6)

- [ ] SIMD-optimized update loop (SSE/AVX)
- [ ] Parallel update (Phase 3)
- [ ] Color/size variation
- [ ] Emitter patterns
