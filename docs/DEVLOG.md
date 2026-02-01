# 开发日志 - Sim-Architecture-Lab

> A 22-week training program for high-performance C++ simulation systems.

---

## 2026-02-01 | Project Restructure

### 🔄 Major Changes

- Restructured project from "Levels" to "Phases" curriculum
- Created 8 phases with 40+ drills and 5 capstones
- Moved Particle Storm to `phase_1_memory/capstone_particle_storm/`
- Added detailed `CURRICULUM.md` with drill specifications
- Updated `.cursorrules` with curriculum context

### 📂 New Structure

```
Sim-Architecture-Lab/
├── phase_0_onboarding/     # C++ fundamentals
├── phase_1_memory/         # Memory architecture
│   └── capstone_particle_storm/
├── phase_2_dod/            # Data-oriented design
├── phase_3_concurrency/    # Multi-threading
├── phase_4_lockfree/       # Lock-free programming
├── phase_5_network/        # Network programming
├── phase_6_simd/           # SIMD optimization
└── phase_7_distributed/    # Distributed simulation
```

### 🎯 Timeline

| Month | Phases | Milestone |
|:------|:-------|:----------|
| Feb 2026 | 0, 1 | C++ fluency, Particle Storm polished |
| Mar 2026 | 2, 3 | DOD, Threading basics |
| Apr 2026 | 3 | Parallel Particle System |
| May 2026 | 4 | Lock-free, Traffic Grid |
| Jun 2026 | 5 | Network programming |
| Jul 2026 | 6, 7 | SIMD, Distributed basics |
| Aug 2026 | 7 | Mirror World, Lab complete |
| Sep 2026 | - | OMSCS GIOS begins |

---

## 2026-01-27 | Phase 1: Particle Storm - Day 1

### ✅ 完成项

| 任务 | 状态 |
|:-----|:-----|
| 项目结构搭建 | ✅ |
| CMake 配置（FetchContent + Raylib） | ✅ |
| WSL 开发环境配置 | ✅ |
| ParticleSystem 核心实现 | ✅ |
| 主循环框架 | ✅ |
| 首次成功编译 | ✅ |

### 📂 当前项目结构

```
Sim-Architecture-Lab/
├── CMakeLists.txt              # 根 CMake
├── scripts/
│   └── setup_ubuntu.sh         # 环境配置脚本
├── docs/
│   └── DEVLOG.md               # 开发日志（本文件）
└── level_1_particle_storm/
    ├── CMakeLists.txt
    └── src/
        ├── main.cpp            # 主循环
        ├── particle_system.h   # 粒子系统头文件
        └── particle_system.cpp # 粒子系统实现
```

### 🧠 今日学习要点

#### 1. SOA vs AOS

```
AOS (Array of Structs) - 不好:
struct Particle { float x, y, z, vx, vy, vz; };
Particle particles[N];  // 内存: [x,y,z,vx,vy,vz][x,y,z,vx,vy,vz]...

SOA (Struct of Arrays) - 好:
float position_x[N];
float position_y[N];
float position_z[N];
// 内存: [x,x,x,x,x...][y,y,y,y,y...][z,z,z,z,z...]
```

**优势：** 
- 更高的缓存命中率（只加载需要的数据）
- SIMD 友好（连续数据可向量化处理）

#### 2. Cache Line 与内存布局

- 现代 CPU 以 **64 bytes** 为单位从内存加载数据（Cache Line）
- 数据结构大小应为 64 的因数或倍数，避免 Cache Line Split
- `float` = 4 bytes，一个 Cache Line 可装 16 个 float

#### 3. SIMD 寄存器大小（重要纠错）

| 指令集 | 寄存器宽度 | float 数量 |
|:-------|:-----------|:-----------|
| SSE | 128 **bits** | 4 |
| AVX | 256 **bits** | 8 |
| AVX-512 | 512 **bits** | 16 |

**单位是 bits，不是 bytes！**

#### 4. Swap-and-Pop 内存管理

用于无分支、O(1) 的对象池管理：

```cpp
void kill(size_t index) {
    size_t last = active_count_ - 1;
    std::swap(data[index], data[last]);
    --active_count_;
}
```

**优势：**
- 无运行时堆分配
- Update 循环无分支（只遍历 active 区域）
- 顺序不稳定，但粒子系统不需要稳定顺序

#### 5. std::vector - reserve() vs resize()

| 函数 | 效果 |
|:-----|:-----|
| `reserve(n)` | 分配内存，`size()` 不变 |
| `resize(n)` | 分配内存 + 初始化元素，`size() = n` |

对于预分配的对象池，用 `resize()` 才能安全地用 `[]` 访问。

#### 6. CMake 构建系统

**两阶段构建：**

| 阶段 | 命令 | 作用 |
|:-----|:-----|:-----|
| 配置（Configure） | `cmake -B build` | 检测环境、下载依赖、生成 Makefile |
| 构建（Build） | `cmake --build build` | 实际编译源文件 |

**何时需要重新配置：**

| 场景 | 需要 `cmake -B build`？ |
|:-----|:----------------------|
| 修改 `.cpp` / `.h` | ❌ 直接 build |
| 修改 `CMakeLists.txt` | ❌ 自动检测 |
| 删除 `build/` 目录 | ✅ 需要 |
| 首次 clone 项目 | ✅ 需要 |
| 切换 Debug/Release | ✅ 需要 |

#### 7. 并行编译 `-j$(nproc)`

```bash
cmake --build build -j$(nproc)
```

| 部分 | 含义 |
|:-----|:-----|
| `-j` | 并行任务数（jobs） |
| `$(nproc)` | Shell 命令替换，返回 CPU 核心数 |

**效果：** 8 核 CPU 同时编译 8 个文件，大幅缩短编译时间。

#### 8. FetchContent 依赖管理

```cmake
include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.5
    GIT_SHALLOW TRUE  # 只克隆最新提交，节省时间
)
FetchContent_MakeAvailable(raylib)
```

- 首次 `cmake -B build` 时自动下载依赖
- 依赖源码在 `build/_deps/` 目录
- 不需要手动安装系统库

#### 9. compile_commands.json

```cmake
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
```

- CMake 生成的编译数据库
- 包含每个源文件的编译命令和 include 路径
- IDE（Cursor/VSCode/clangd）用它提供准确的代码补全
- 需要软链接到项目根目录：`ln -sf build/compile_commands.json .`

#### 10. 环境配置脚本使用场景

`scripts/setup_ubuntu.sh` **只需运行一次**：

| 场景 | 运行？ |
|:-----|:------|
| 新机器 / 新 WSL | ✅ |
| 系统重装后 | ✅ |
| `git clone` 到新环境 | ✅ |
| 日常开发 | ❌ |

---

### 🔜 待办（下次继续）

- [ ] 添加粒子发射器（Emitter）逻辑
- [ ] 实现粒子生命周期（lifetime → 自动 kill）
- [ ] 压力测试：100,000 粒子 @ 60 FPS
- [ ] 可选：SIMD 优化 update 循环

---

### 📌 常用命令

```bash
# 构建
cmake -B build && cmake --build build -j$(nproc)

# 运行
./bin/L1_ParticleStorm

# 环境配置（新机器）
./scripts/setup_ubuntu.sh
```
