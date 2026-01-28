# Sim-Architecture-Lab

A high-performance simulation systems laboratory focused on CPU-side architecture, memory optimization, and data-oriented design patterns.

## Overview

This repository contains a series of simulation projects exploring performance-critical C++ systems programming. Each project targets specific architectural challenges commonly encountered in real-time simulation, game engines, and autonomous vehicle systems.

**Core Focus Areas:**
- Data-Oriented Design (DOD) over Object-Oriented Programming
- Cache-friendly memory layouts and SIMD optimization
- Lock-free concurrency patterns
- Zero-allocation runtime architectures

## Projects

| Project | Description | Status |
|:--------|:------------|:-------|
| **Particle Storm** | High-throughput particle system (100K+ particles @ 60fps) | 🚧 Active |
| **Traffic Grid** | Multi-agent traffic simulation with lock-free data structures | Planned |
| **Mirror World** | Distributed simulation synchronization | Planned |
| **Sensor Fusion** | Physics-based sensor simulation pipeline | Planned |

## Tech Stack

- **Language:** C++20
- **Build:** CMake 3.15+
- **Visualization:** Raylib
- **Platform:** Linux / WSL2

## Build

```bash
# First-time setup (Ubuntu/WSL)
./scripts/setup_ubuntu.sh

# Configure
cmake -B build

# Build
cmake --build build -j$(nproc)

# Run
./bin/L1_ParticleStorm
```

## Architecture Principles

This lab adheres to strict performance constraints:

- **No runtime heap allocation** in hot paths
- **No virtual functions** in update loops
- **SOA (Struct of Arrays)** over AOS for simulation data
- **Pre-allocated object pools** with swap-and-pop lifecycle management

## License

MIT
