# Phase 6: SIMD Optimization

**Duration:** 2 weeks  
**Goal:** Utilize CPU vector units for maximum throughput.

## Drills

| # | Name | Status | Skills |
|:--|:-----|:-------|:-------|
| 6.1 | SIMD Introduction | ⬜ | Vector concepts |
| 6.2 | SSE Intrinsics | ⬜ | `__m128`, 4-wide ops |
| 6.3 | AVX Intrinsics | ⬜ | `__m256`, 8-wide ops |
| 6.4 | Auto-vectorization | ⬜ | Compiler flags |
| 6.5 | SIMD Data Layout | ⬜ | Alignment |

## Capstone

| Project | Status |
|:--------|:-------|
| **SIMD Particle Storm** | ⬜ Not Started |

Vectorized particle update with 4x-8x speedup.

## Completion Criteria

- [ ] Can write SSE and AVX code with intrinsics
- [ ] Understand memory alignment requirements
- [ ] Can measure and compare vectorization speedup
- [ ] Know when to use manual vs auto-vectorization

## Resources

- [Intel Intrinsics Guide](https://www.intel.com/content/www/us/en/docs/intrinsics-guide/)
- [SIMD Visualizer](https://piotte13.github.io/SIMD-Visualiser/)
