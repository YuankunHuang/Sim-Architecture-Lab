# Phase 1: Memory Architecture

**Duration:** 2 weeks  
**Goal:** Take complete control over memory allocation.

## Drills

| # | Name | Status | Skills |
|:--|:-----|:-------|:-------|
| 1.1 | Raw Pointers | ⬜ | Pointer arithmetic, `malloc`/`free` |
| 1.2 | Stack vs Heap | ⬜ | Allocation performance |
| 1.3 | Memory Arena | ⬜ | Linear allocator |
| 1.4 | Object Pool | ⬜ | `placement new`, free-list |
| 1.5 | Alignment | ⬜ | `alignas`, cache line |

## Capstone

| Project | Status |
|:--------|:-------|
| **Particle Storm** | ✅ Complete |

100,000 particles @ 60 FPS with zero runtime allocation.

## Completion Criteria

- [ ] Can implement custom memory allocator
- [ ] Understand stack vs heap trade-offs
- [ ] Can use `placement new` for object pools
- [ ] Understand cache line alignment

## Resources

- [What Every Programmer Should Know About Memory](https://www.akkadia.org/drepper/cpumemory.pdf)
