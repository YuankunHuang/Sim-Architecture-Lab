# Sim-Architecture-Lab Curriculum

> A structured 22-week training program for high-performance C++ simulation systems.

---

## Phase 0: C++ Onboarding (2 weeks)

**Goal:** Transition from C# thinking to C++ thinking.

| Drill | Name | Skills | Est. Time |
|:------|:-----|:-------|:----------|
| 0.1 | Hello CMake | CMake targets, FetchContent, compile_commands.json | 2h |
| 0.2 | RAII & Smart Pointers | `unique_ptr`, `shared_ptr`, RAII principle | 4h |
| 0.3 | Move Semantics | Rvalue references, `std::move`, copy elision | 4h |
| 0.4 | Templates 101 | Function/class templates, type deduction | 4h |
| 0.5 | STL Deep Dive | `vector`, `unordered_map`, iterators, algorithms | 4h |

**Capstone:** None (foundation phase)

### Drill 0.1: Hello CMake

**Objective:** Understand the CMake build system.

**Tasks:**
- [ ] Create a minimal CMake project with `add_executable`
- [ ] Add a library with `add_library` and link it
- [ ] Use `FetchContent` to pull a dependency
- [ ] Generate and use `compile_commands.json`

**Deliverable:** A multi-target project that builds and runs.

### Drill 0.2: RAII & Smart Pointers

**Objective:** Master automatic resource management.

**Tasks:**
- [ ] Implement a `FileHandle` class with RAII
- [ ] Convert raw pointer code to `unique_ptr`
- [ ] Understand when to use `shared_ptr` vs `unique_ptr`
- [ ] Implement custom deleter

**Deliverable:** Zero-leak resource management examples.

### Drill 0.3: Move Semantics

**Objective:** Understand move semantics for performance.

**Tasks:**
- [ ] Implement a `Buffer` class with move constructor/assignment
- [ ] Benchmark copy vs move for large containers
- [ ] Use `std::move` correctly in function calls
- [ ] Understand copy elision (RVO/NRVO)

**Deliverable:** Performance comparison showing move benefits.

### Drill 0.4: Templates 101

**Objective:** Write generic, type-safe code.

**Tasks:**
- [ ] Implement a generic `max()` function
- [ ] Implement a generic `Array<T, N>` container
- [ ] Use `auto` return type deduction
- [ ] Basic SFINAE: `enable_if` for numeric types only

**Deliverable:** Reusable template utilities.

### Drill 0.5: STL Deep Dive

**Objective:** Master the Standard Template Library.

**Tasks:**
- [ ] Benchmark `vector` vs `list` for random access
- [ ] Implement custom hash for `unordered_map`
- [ ] Use `<algorithm>` for sorting, searching, transforming
- [ ] Range-based for vs iterator-based loops

**Deliverable:** STL usage patterns document.

---

## Phase 1: Memory Architecture (2 weeks)

**Goal:** Take complete control over memory allocation.

| Drill | Name | Skills | Est. Time |
|:------|:-----|:-------|:----------|
| 1.1 | Raw Pointers | Pointer arithmetic, `malloc`/`free` | 3h |
| 1.2 | Stack vs Heap | Allocation performance, stack limits | 2h |
| 1.3 | Memory Arena | Linear allocator, bulk free | 4h |
| 1.4 | Object Pool | Pre-allocation, `placement new` | 4h |
| 1.5 | Alignment | `alignas`, cache line alignment | 3h |

**Capstone:** Particle Storm ✅ (100K particles @ 60fps, zero allocation)

### Drill 1.1: Raw Pointers

**Objective:** Understand pointer fundamentals.

**Tasks:**
- [ ] Implement array operations using pointer arithmetic
- [ ] Manual memory management with `malloc`/`free`
- [ ] Understand pointer aliasing and strict aliasing rule
- [ ] Debug memory issues with Valgrind/AddressSanitizer

**Deliverable:** Working pointer-based data structure.

### Drill 1.2: Stack vs Heap

**Objective:** Understand allocation trade-offs.

**Tasks:**
- [ ] Benchmark stack allocation vs heap allocation
- [ ] Measure stack overflow limits
- [ ] Implement stack-allocated fixed-size container
- [ ] Profile with `perf` or similar tool

**Deliverable:** Performance comparison document.

### Drill 1.3: Memory Arena

**Objective:** Implement a linear allocator.

**Tasks:**
- [ ] Allocate a large block upfront
- [ ] Implement `alloc()` that bumps a pointer
- [ ] Implement `reset()` that resets to beginning
- [ ] Use for frame-temporary allocations

**Deliverable:** `MemoryArena` class with tests.

### Drill 1.4: Object Pool

**Objective:** Implement a reusable object pool.

**Tasks:**
- [ ] Pre-allocate N objects
- [ ] Use free-list for O(1) alloc/free
- [ ] Use `placement new` for construction
- [ ] Implement swap-and-pop for iteration

**Deliverable:** `ObjectPool<T>` template class.

### Drill 1.5: Alignment

**Objective:** Optimize for cache line access.

**Tasks:**
- [ ] Use `alignas(64)` for cache line alignment
- [ ] Measure false sharing in multi-threaded code
- [ ] Implement aligned allocator
- [ ] Analyze struct padding with `sizeof`/`offsetof`

**Deliverable:** Aligned data structures with benchmarks.

### Capstone 1: Particle Storm

**Status:** ✅ Complete

**Specs:**
- 100,000 particles @ 60 FPS
- Zero runtime allocation
- SOA data layout
- Swap-and-pop lifecycle

---

## Phase 2: Data-Oriented Design (2 weeks)

**Goal:** Make the CPU cache your best friend.

| Drill | Name | Skills | Est. Time |
|:------|:-----|:-------|:----------|
| 2.1 | AOS vs SOA Benchmark | Layout comparison, cache effects | 3h |
| 2.2 | Cache Line Experiment | `perf stat`, cache miss measurement | 3h |
| 2.3 | Hot/Cold Splitting | Separate frequently/rarely used data | 3h |
| 2.4 | Data Locality | Sequential vs random access patterns | 3h |
| 2.5 | Struct Packing | `#pragma pack`, padding analysis | 2h |

**Capstone:** None (concepts applied in future capstones)

### Drill 2.1: AOS vs SOA Benchmark

**Objective:** Measure the performance difference.

**Tasks:**
- [ ] Implement particle update with AOS layout
- [ ] Implement particle update with SOA layout
- [ ] Benchmark both with 1M particles
- [ ] Analyze with `perf stat` (cache misses)

**Deliverable:** Performance comparison with analysis.

### Drill 2.2: Cache Line Experiment

**Objective:** Visualize cache behavior.

**Tasks:**
- [ ] Create array traversal with different strides
- [ ] Measure L1/L2/L3 cache miss rates
- [ ] Identify the 64-byte cache line boundary
- [ ] Document the "memory wall"

**Deliverable:** Cache behavior visualization.

### Drill 2.3: Hot/Cold Splitting

**Objective:** Optimize data layout for access patterns.

**Tasks:**
- [ ] Identify hot (every frame) vs cold (rare) data
- [ ] Split `Entity` into `EntityCore` + `EntityMetadata`
- [ ] Benchmark iteration over hot data only
- [ ] Document when to split vs keep together

**Deliverable:** Split data structure with benchmarks.

### Drill 2.4: Data Locality

**Objective:** Maximize sequential memory access.

**Tasks:**
- [ ] Benchmark sequential vs random array access
- [ ] Implement entity processing in sorted order
- [ ] Use indices instead of pointers for locality
- [ ] Prefetching hints (`__builtin_prefetch`)

**Deliverable:** Locality-optimized access patterns.

### Drill 2.5: Struct Packing

**Objective:** Minimize memory footprint.

**Tasks:**
- [ ] Analyze padding with `sizeof`/`offsetof`
- [ ] Reorder struct members for minimal padding
- [ ] Use `#pragma pack` judiciously
- [ ] Understand alignment requirements

**Deliverable:** Optimally packed structures.

---

## Phase 3: Concurrency Foundations (4 weeks)

**Goal:** Master multi-threaded programming (GIOS prep).

| Drill | Name | Skills | Est. Time |
|:------|:-----|:-------|:----------|
| 3.1 | Thread Creation | `std::thread`, `pthread` | 3h |
| 3.2 | Mutex Basics | `std::mutex`, critical section | 3h |
| 3.3 | Deadlock Lab | Deadlock creation and prevention | 3h |
| 3.4 | Condition Variables | Wait/notify pattern | 4h |
| 3.5 | Producer-Consumer | Classic synchronization problem | 4h |
| 3.6 | Thread Pool | Task queue, worker threads | 6h |
| 3.7 | Readers-Writer Lock | `shared_mutex`, read-heavy optimization | 4h |
| 3.8 | Thread-Safe Containers | Concurrent data structures | 4h |

**Capstone:** Parallel Particle System (multi-threaded particle update)

### Drill 3.1: Thread Creation

**Objective:** Create and manage threads.

**Tasks:**
- [ ] Create threads with `std::thread`
- [ ] Pass arguments to thread function
- [ ] Join and detach threads
- [ ] Use `std::jthread` (C++20)

**Deliverable:** Multi-threaded hello world with variations.

### Drill 3.2: Mutex Basics

**Objective:** Protect shared data.

**Tasks:**
- [ ] Implement counter with race condition
- [ ] Fix with `std::mutex`
- [ ] Use `std::lock_guard` / `std::unique_lock`
- [ ] Measure mutex overhead

**Deliverable:** Thread-safe counter with benchmarks.

### Drill 3.3: Deadlock Lab

**Objective:** Understand and prevent deadlock.

**Tasks:**
- [ ] Create a deadlock scenario
- [ ] Detect deadlock with debugger
- [ ] Fix with lock ordering
- [ ] Use `std::scoped_lock` for multi-mutex

**Deliverable:** Deadlock examples with fixes.

### Drill 3.4: Condition Variables

**Objective:** Implement wait/notify patterns.

**Tasks:**
- [ ] Use `std::condition_variable` for signaling
- [ ] Implement bounded buffer
- [ ] Avoid spurious wakeups
- [ ] Understand the "lost wakeup" problem

**Deliverable:** Condition variable patterns.

### Drill 3.5: Producer-Consumer

**Objective:** Solve the classic synchronization problem.

**Tasks:**
- [ ] Single producer, single consumer
- [ ] Multiple producers, single consumer
- [ ] Multiple producers, multiple consumers
- [ ] Measure throughput

**Deliverable:** Producer-consumer implementation with benchmarks.

### Drill 3.6: Thread Pool

**Objective:** Build a reusable thread pool.

**Tasks:**
- [ ] Create fixed-size pool of worker threads
- [ ] Implement task queue with mutex + condvar
- [ ] Submit tasks and wait for completion
- [ ] Graceful shutdown

**Deliverable:** `ThreadPool` class with tests.

### Drill 3.7: Readers-Writer Lock

**Objective:** Optimize for read-heavy workloads.

**Tasks:**
- [ ] Implement with `std::shared_mutex`
- [ ] Benchmark vs regular mutex
- [ ] Understand writer starvation
- [ ] Implement fair RW lock

**Deliverable:** RW lock with benchmarks.

### Drill 3.8: Thread-Safe Containers

**Objective:** Build concurrent data structures.

**Tasks:**
- [ ] Implement thread-safe queue
- [ ] Implement thread-safe hash map (coarse-grained)
- [ ] Measure contention
- [ ] Compare with lock-free (Phase 4)

**Deliverable:** Thread-safe containers.

### Capstone 3: Parallel Particle System

**Objective:** Multi-threaded Particle Storm.

**Specs:**
- Parallelize update loop across N threads
- Use thread pool from Drill 3.6
- Partition particles into chunks
- Achieve near-linear speedup

**Deliverable:** Parallel particle system with speedup analysis.

---

## Phase 4: Lock-Free Programming (3 weeks)

**Goal:** Master atomic operations and lock-free algorithms.

| Drill | Name | Skills | Est. Time |
|:------|:-----|:-------|:----------|
| 4.1 | Atomic Operations | `std::atomic`, load/store | 3h |
| 4.2 | Memory Ordering | `memory_order` flags | 4h |
| 4.3 | Compare-and-Swap | CAS operation, spinlock | 4h |
| 4.4 | Lock-Free Stack | Treiber stack | 4h |
| 4.5 | Lock-Free Queue | Michael-Scott queue, SPSC | 6h |
| 4.6 | ABA Problem | Hazard pointers, tagged pointers | 4h |

**Capstone:** Traffic Grid (multi-agent simulation with lock-free communication)

### Drill 4.1: Atomic Operations

**Objective:** Understand atomic primitives.

**Tasks:**
- [ ] Use `std::atomic<int>` for counter
- [ ] Compare with volatile (wrong approach)
- [ ] Use `fetch_add`, `exchange`
- [ ] Understand atomic flags

**Deliverable:** Atomic counter implementations.

### Drill 4.2: Memory Ordering

**Objective:** Master memory order semantics.

**Tasks:**
- [ ] Understand `memory_order_seq_cst` (default)
- [ ] Use `acquire`/`release` for synchronization
- [ ] Use `relaxed` for independent counters
- [ ] Create example showing reordering

**Deliverable:** Memory ordering examples with explanations.

### Drill 4.3: Compare-and-Swap

**Objective:** Build lock-free primitives with CAS.

**Tasks:**
- [ ] Implement spinlock with `compare_exchange`
- [ ] Understand the CAS loop pattern
- [ ] Implement lock-free counter update
- [ ] Backoff strategies for contention

**Deliverable:** CAS-based primitives.

### Drill 4.4: Lock-Free Stack

**Objective:** Implement Treiber stack.

**Tasks:**
- [ ] Implement push with CAS
- [ ] Implement pop with CAS
- [ ] Handle empty stack correctly
- [ ] Test with multiple threads

**Deliverable:** Lock-free stack with stress tests.

### Drill 4.5: Lock-Free Queue

**Objective:** Implement lock-free queues.

**Tasks:**
- [ ] SPSC (Single Producer Single Consumer) ring buffer
- [ ] MPSC queue
- [ ] MPMC queue (Michael-Scott)
- [ ] Benchmark vs mutex-based queue

**Deliverable:** Lock-free queue implementations.

### Drill 4.6: ABA Problem

**Objective:** Understand and solve ABA.

**Tasks:**
- [ ] Create ABA scenario
- [ ] Solve with tagged pointers (version counter)
- [ ] Understand hazard pointers concept
- [ ] Research epoch-based reclamation

**Deliverable:** ABA problem demonstration and solution.

### Capstone 4: Traffic Grid

**Objective:** Multi-agent traffic simulation.

**Specs:**
- 10,000+ vehicles
- Grid-based spatial partitioning
- Lock-free message passing between cells
- Collision avoidance behaviors

**Deliverable:** Traffic simulation with visualization.

---

## Phase 5: Network Programming (3 weeks)

**Goal:** Master socket programming (GIOS prep).

| Drill | Name | Skills | Est. Time |
|:------|:-----|:-------|:----------|
| 5.1 | Socket Basics | `socket`, `bind`, `listen`, `accept` | 4h |
| 5.2 | TCP Echo Server | Blocking TCP server | 4h |
| 5.3 | UDP Basics | `sendto`, `recvfrom` | 3h |
| 5.4 | Non-blocking I/O | `fcntl`, `O_NONBLOCK` | 4h |
| 5.5 | I/O Multiplexing | `select`, `epoll` | 5h |
| 5.6 | Multi-threaded Server | Thread-per-connection, thread pool | 5h |

**Capstone:** None (concepts applied in Phase 7)

### Drill 5.1: Socket Basics

**Objective:** Understand Berkeley sockets API.

**Tasks:**
- [ ] Create TCP socket
- [ ] Bind to address and port
- [ ] Listen for connections
- [ ] Accept and handle client

**Deliverable:** Basic TCP server.

### Drill 5.2: TCP Echo Server

**Objective:** Build a functional server.

**Tasks:**
- [ ] Implement echo protocol
- [ ] Handle multiple clients sequentially
- [ ] Proper error handling
- [ ] Graceful shutdown

**Deliverable:** Working echo server.

### Drill 5.3: UDP Basics

**Objective:** Understand connectionless communication.

**Tasks:**
- [ ] Create UDP socket
- [ ] Send and receive datagrams
- [ ] Understand packet loss
- [ ] Compare with TCP performance

**Deliverable:** UDP echo server.

### Drill 5.4: Non-blocking I/O

**Objective:** Avoid blocking on I/O.

**Tasks:**
- [ ] Set socket to non-blocking
- [ ] Handle `EWOULDBLOCK`/`EAGAIN`
- [ ] Implement polling loop
- [ ] Measure CPU usage

**Deliverable:** Non-blocking server.

### Drill 5.5: I/O Multiplexing

**Objective:** Handle many connections efficiently.

**Tasks:**
- [ ] Use `select()` for basic multiplexing
- [ ] Use `epoll()` for scalable I/O
- [ ] Understand edge-triggered vs level-triggered
- [ ] Benchmark connection scaling

**Deliverable:** epoll-based server.

### Drill 5.6: Multi-threaded Server

**Objective:** Combine threads and networking.

**Tasks:**
- [ ] Thread-per-connection model
- [ ] Thread pool with connection queue
- [ ] Compare architectures
- [ ] Handle graceful shutdown

**Deliverable:** Multi-threaded server with benchmarks.

---

## Phase 6: SIMD Optimization (2 weeks)

**Goal:** Utilize CPU vector units for maximum throughput.

| Drill | Name | Skills | Est. Time |
|:------|:-----|:-------|:----------|
| 6.1 | SIMD Introduction | Vector registers, operations | 2h |
| 6.2 | SSE Intrinsics | `__m128`, 4-wide operations | 4h |
| 6.3 | AVX Intrinsics | `__m256`, 8-wide operations | 4h |
| 6.4 | Auto-vectorization | Compiler flags, vectorization reports | 3h |
| 6.5 | SIMD Data Layout | 16/32-byte alignment | 3h |

**Capstone:** SIMD Particle Storm (vectorized particle update)

### Drill 6.1: SIMD Introduction

**Objective:** Understand SIMD concepts.

**Tasks:**
- [ ] Understand vector registers (XMM, YMM, ZMM)
- [ ] Identify SIMD-friendly operations
- [ ] Check CPU capabilities with `cpuid`
- [ ] Understand instruction latency/throughput

**Deliverable:** SIMD concepts document.

### Drill 6.2: SSE Intrinsics

**Objective:** Write SSE code.

**Tasks:**
- [ ] Include `<immintrin.h>`
- [ ] Load/store with `_mm_load_ps`/`_mm_store_ps`
- [ ] Arithmetic: `_mm_add_ps`, `_mm_mul_ps`
- [ ] Implement dot product

**Deliverable:** SSE utility functions.

### Drill 6.3: AVX Intrinsics

**Objective:** Use wider vectors.

**Tasks:**
- [ ] Use `__m256` for 8-wide floats
- [ ] Handle AVX transitions (vzeroupper)
- [ ] Implement vector operations
- [ ] Benchmark SSE vs AVX

**Deliverable:** AVX implementations with benchmarks.

### Drill 6.4: Auto-vectorization

**Objective:** Let the compiler vectorize.

**Tasks:**
- [ ] Enable `-O3 -march=native`
- [ ] Read vectorization reports (`-fopt-info-vec`)
- [ ] Remove vectorization blockers
- [ ] Compare auto vs manual SIMD

**Deliverable:** Auto-vectorization analysis.

### Drill 6.5: SIMD Data Layout

**Objective:** Align data for SIMD.

**Tasks:**
- [ ] Align arrays to 16/32 bytes
- [ ] Use aligned load/store
- [ ] Handle remainder elements
- [ ] SOA layout for SIMD

**Deliverable:** SIMD-friendly data structures.

### Capstone 6: SIMD Particle Storm

**Objective:** Vectorized particle physics.

**Specs:**
- SSE/AVX particle update
- 4x-8x speedup over scalar
- Aligned SOA layout
- Benchmark comparison

**Deliverable:** SIMD particle system with speedup analysis.

---

## Phase 7: Distributed Simulation (4 weeks)

**Goal:** Synchronize simulation state across network.

| Drill | Name | Skills | Est. Time |
|:------|:-----|:-------|:----------|
| 7.1 | Client-Server Model | Basic architecture | 4h |
| 7.2 | State Serialization | Binary serialization | 4h |
| 7.3 | Delta Compression | Only send changes | 4h |
| 7.4 | Clock Synchronization | NTP-like time sync | 4h |
| 7.5 | Lag Compensation | Client prediction, server reconciliation | 6h |
| 7.6 | Reliable UDP | ACK, retransmission, ordering | 6h |

**Capstone:** Mirror World (networked simulation)

### Drill 7.1: Client-Server Model

**Objective:** Design distributed architecture.

**Tasks:**
- [ ] Server as authoritative state holder
- [ ] Client as input sender / state receiver
- [ ] Define message protocol
- [ ] Handle client connect/disconnect

**Deliverable:** Client-server framework.

### Drill 7.2: State Serialization

**Objective:** Efficiently encode simulation state.

**Tasks:**
- [ ] Binary serialization (not JSON/XML)
- [ ] Fixed-width types for portability
- [ ] Handle endianness
- [ ] Measure serialization overhead

**Deliverable:** Serialization library.

### Drill 7.3: Delta Compression

**Objective:** Send only what changed.

**Tasks:**
- [ ] Track dirty flags per entity
- [ ] Send full state initially
- [ ] Send deltas subsequently
- [ ] Handle packet loss with full re-sync

**Deliverable:** Delta compression system.

### Drill 7.4: Clock Synchronization

**Objective:** Align client/server time.

**Tasks:**
- [ ] Measure round-trip time (RTT)
- [ ] Estimate clock offset
- [ ] NTP-style averaging
- [ ] Handle clock drift

**Deliverable:** Time synchronization implementation.

### Drill 7.5: Lag Compensation

**Objective:** Hide network latency from users.

**Tasks:**
- [ ] Client-side prediction
- [ ] Server reconciliation
- [ ] Entity interpolation
- [ ] Rollback for corrections

**Deliverable:** Lag compensation system.

### Drill 7.6: Reliable UDP

**Objective:** Build reliability on top of UDP.

**Tasks:**
- [ ] Sequence numbers
- [ ] Acknowledgements
- [ ] Retransmission
- [ ] Ordering

**Deliverable:** Reliable UDP library.

### Capstone 7: Mirror World

**Objective:** Networked distributed simulation.

**Specs:**
- 1 server + 2+ clients
- Shared particle world
- Real-time synchronization
- < 100ms apparent latency

**Deliverable:** Networked simulation with demo video.

---

## Summary: Capstone Projects

| # | Name | Phase | Core Skills Demonstrated |
|:--|:-----|:------|:-------------------------|
| 1 | **Particle Storm** | 1 | Memory, DOD, Zero-allocation |
| 2 | **Parallel Particle System** | 3 | Multi-threading, Thread pool |
| 3 | **Traffic Grid** | 4 | Lock-free, Spatial partitioning |
| 4 | **SIMD Particle Storm** | 6 | Vectorization, SIMD intrinsics |
| 5 | **Mirror World** | 7 | Networking, Distributed systems |

---

## Timeline

| Month | Phases | Milestone |
|:------|:-------|:----------|
| Feb 2026 | 0, 1 | C++ fluency, Particle Storm polished |
| Mar 2026 | 2, 3 (partial) | DOD mastery, Threading basics |
| Apr 2026 | 3 (complete) | Parallel Particle System |
| May 2026 | 4 | Lock-free, Traffic Grid |
| Jun 2026 | 5 | Network programming |
| Jul 2026 | 6, 7 (partial) | SIMD, Distributed basics |
| Aug 2026 | 7 (complete) | Mirror World, Lab complete |
| Sep 2026 | OMSCS | GIOS begins |

---

## Resources

### Books
- *Effective Modern C++* - Scott Meyers
- *C++ Concurrency in Action* - Anthony Williams
- *Game Programming Patterns* - Robert Nystrom (free online)

### Online
- *Beej's Guide to Network Programming* (for Phase 5)
- *Intel Intrinsics Guide* (for Phase 6)
- CppCon talks on YouTube

### Tools
- **Valgrind/ASan** - Memory debugging
- **perf** - Performance profiling
- **ThreadSanitizer** - Data race detection
