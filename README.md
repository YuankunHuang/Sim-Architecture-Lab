# Sim-Architecture-Lab

> **"Making the invisible visible."**

A structured training program for transitioning from Unity/C# game development to high-performance C++ simulation systems engineering.

## Overview

This lab is designed as a **22-week curriculum** covering the core skills needed for simulation systems architecture:

- Memory Architecture & Control
- Data-Oriented Design
- Concurrent & Lock-Free Programming
- Network Programming
- SIMD Optimization
- Distributed Simulation

**Target Outcome:** Complete this lab before OMSCS begins (Fall 2026), with a portfolio of C++ projects demonstrating systems-level thinking.

## Curriculum Structure

| Phase | Topic | Duration | Capstone |
|:------|:------|:---------|:---------|
| **0** | C++ Onboarding | 2 weeks | - |
| **1** | Memory Architecture | 2 weeks | Particle Storm |
| **2** | Data-Oriented Design | 2 weeks | - |
| **3** | Concurrency | 4 weeks | Parallel Particle System |
| **4** | Lock-Free Programming | 3 weeks | Traffic Grid |
| **5** | Network Programming | 3 weeks | - |
| **6** | SIMD Optimization | 2 weeks | SIMD Particle Storm |
| **7** | Distributed Simulation | 4 weeks | Mirror World |

**Total: 22 weeks (~5.5 months)**

See [docs/CURRICULUM.md](docs/CURRICULUM.md) for detailed drill and capstone specifications.

## Tech Stack

| Component | Choice |
|:----------|:-------|
| Language | C++20 |
| Build | CMake 3.15+ |
| Visualization | Raylib 5.5 |
| Platform | Linux / WSL2 |

## Quick Start

```bash
# First-time setup (Ubuntu/WSL)
./scripts/setup_ubuntu.sh

# Configure & Build
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j$(nproc)

# Run current capstone
./bin/P1_ParticleStorm
```

## Architecture Principles

This lab adheres to strict performance constraints:

| Principle | Rule |
|:----------|:-----|
| **Zero Allocation** | No runtime heap allocation in hot paths |
| **No Virtual** | No virtual functions in update loops |
| **SOA over AOS** | Struct of Arrays for simulation data |
| **Cache Conscious** | 64-byte alignment, sequential access |
| **Lock-Free Preferred** | Use atomic operations over mutex when possible |

## Progress Tracking

| Phase | Status | Completion |
|:------|:-------|:-----------|
| Phase 0: C++ Onboarding | 🟡 In Progress | - |
| Phase 1: Memory Architecture | 🟢 Capstone Done | Particle Storm ✅ |
| Phase 2: DOD | ⬜ Not Started | - |
| Phase 3: Concurrency | ⬜ Not Started | - |
| Phase 4: Lock-Free | ⬜ Not Started | - |
| Phase 5: Network | ⬜ Not Started | - |
| Phase 6: SIMD | ⬜ Not Started | - |
| Phase 7: Distributed | ⬜ Not Started | - |

## Directory Structure

```
Sim-Architecture-Lab/
├── README.md
├── CMakeLists.txt
├── docs/
│   ├── CURRICULUM.md          # Full curriculum with drill specs
│   └── DEVLOG.md              # Development journal
├── phase_0_onboarding/        # C++ fundamentals
├── phase_1_memory/            # Memory architecture
│   └── capstone_particle_storm/
├── phase_2_dod/               # Data-oriented design
├── phase_3_concurrency/       # Multi-threading
│   └── capstone_parallel_particle/
├── phase_4_lockfree/          # Lock-free programming
│   └── capstone_traffic_grid/
├── phase_5_network/           # Network programming
├── phase_6_simd/              # SIMD optimization
│   └── capstone_simd_particle/
├── phase_7_distributed/       # Distributed simulation
│   └── capstone_mirror_world/
└── scripts/
    └── setup_ubuntu.sh
```

## License

MIT
