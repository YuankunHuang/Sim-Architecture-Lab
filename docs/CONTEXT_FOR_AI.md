# AI Context Document

> 下次对话开始时，将此文档发给 AI，以快速恢复上下文。

---

## 关于我

### 基本信息
- **身份**：高级 Unity/C# 游戏开发者，5+ 年移动游戏开发经验
- **现状**：就职于 IGG Canada（温哥华），做放置类手游
- **教育背景**：北京邮电大学本科 → CDM MDM 硕士 → 已获 OMSCS 录取（2026年9月入学）
- **身份**：加拿大 PR

### 核心哲学

> **"Making the invisible visible."**

我的创作冲动源于将看不见的事物可视化：
- 大学时做"音频可视化播放器"——把音乐变成屏幕上飞舞的线条
- 现在做 Kodama——让一个"世界"从无到有自行生长

我不想做"台前表演"的人，我想做"幕后负重前行"的人。我想在聚光灯外享受掌声。

### 性格特征
- **理想主义者**，但被现实教会了务实
- 有"造物主情结"，渴望创造"大"的东西
- 对当下工作（做赚钱手游）失去热情，但有经济压力
- 愿意长期投入，但渴望突破收入瓶颈

---

## 我想要的

### 短期目标（2026年内）
1. **薪资突破**：至少 100K CAD（税前），相比现状有显著提升
2. **技术转型**：从纯游戏开发 → 仿真/系统工程方向
3. **技能补齐**：C++、并发、网络编程、底层系统知识

### 中长期目标（3年）
1. **完成 OMSCS**：重点课程：GIOS、HPC、分布式计算
2. **职业定位**：Infra Architect / Simulation Systems Engineer
3. **代表作**：Kodama（C#后端+Unity前端）+ Sim-Architecture-Lab（纯C++）

### 终极愿景
进入"真正有意义"的仿真领域：
- 工业仿真、数字孪生
- AI 训练用的合成数据生成
- 或任何"让不可见变得可见"的技术领域

---

## 我要做的

### 项目 1：Kodama（进行中）
- **定位**：C# 后端 + Unity 前端的大规模仿真 Demo
- **技术亮点**：10K agents、<1ms tick、零 GC、Server-Authoritative
- **目标**：打磨成"让任何人眼前一亮"的个人代表作
- **路径**：`p:\Kodama\`

### 项目 2：Sim-Architecture-Lab（进行中）
- **定位**：22 周 C++ 高性能仿真系统训练计划
- **8 个阶段**：C++ 入门 → 内存 → DOD → 并发 → 无锁 → 网络 → SIMD → 分布式
- **5 个 Capstone**：Particle Storm ✅ → Parallel Particle → Traffic Grid → SIMD Particle → Mirror World
- **目标**：入学 OMSCS 前完成，建立 C++ 底层能力
- **路径**：`p:\Sim-Architecture-Lab\`

### 项目 3：StadiumSim（暂缓）
- **定位**：Unreal Engine 5 人群仿真项目
- **状态**：已有初步框架，但暂时搁置
- **计划**：OMSCS Year 2+ 时再启动，作为 UE/C++ 代表作

### OMSCS 计划（2026.09 - 2029）

| 学期 | 课程 | 与项目的关系 |
|------|------|-------------|
| Year 1 Fall | GIOS | Phase 3-5 并发/网络 |
| Year 1 Spring | HPC | Phase 6 SIMD |
| Year 2 Fall | AI4R | - |
| Year 2 Spring | AOS | Kodama 多核优化 |
| Year 3 Fall | DC | Phase 7 分布式 |
| Year 3 Spring | GA | 算法基础 |

---

## 世界是什么样

### 就业市场（2026年初）
- **科技行业**：经历大规模裁员，竞争极其激烈
- **纯后端岗位**：你将与有多年后端经验的人竞争，不利
- **游戏行业**：持续萎缩，不是好的长期赌注
- **仿真领域**：
  - 工业仿真（如 Rockwell）：需要领域知识，门槛高
  - 数字孪生/XR：有机会，但需要展示相关作品
  - 合成数据生成：增长中，但竞争也在加剧

### 适合我的方向
- **Digital Health / Rehab Tech**：你有 TrAIT 项目背景（Neurorehabilitation and Neural Repair 发表）
- **XR / Visualization**：符合你"让不可见变得可见"的哲学
- **Simulation-adjacent Unity/C# roles**：利用现有技能，逐步过渡

### 现实策略
1. **底线**：留在 IGG，保持收入稳定
2. **机会驱动**：遇到好机会就尝试，每次尝试都是学习
3. **项目优先**：无论找工作结果如何，持续建设 Kodama + Sim-Architecture-Lab
4. **OMSCS 是长期杠杆**：3 年后你的竞争力会完全不同

---

## 关键文件路径

| 项目 | 路径 |
|------|------|
| Kodama | `p:\Kodama\` |
| Kodama DEVLOG | `p:\Kodama\DEVLOG.md` |
| Sim-Architecture-Lab | `p:\Sim-Architecture-Lab\` |
| Lab 课程大纲 | `p:\Sim-Architecture-Lab\docs\CURRICULUM.md` |
| Lab DEVLOG | `p:\Sim-Architecture-Lab\docs\DEVLOG.md` |
| TrAIT 项目 | `p:\UnityProjects\HIVE-Rehab\` |
| StadiumSim | `p:\StadiumSim\` |
| OMSCS 计划 | `c:\Users\buptf\Downloads\OMSCS_Timeline.md` |

---

## 与 AI 的交互约定

### 角色设定
你是 **Lead System Architect & Socratic Mentor**。
- 不要直接给代码，先问我架构问题
- 如果我的代码有问题，狠狠批评（内存分配、线程安全、缓存效率）
- 如果我问方向性问题，帮我做 trade-off 分析，但最终决定权在我

### 沟通风格
- 使用简体中文
- 技术术语可以用英文
- 不要空洞的鼓励，要务实的建议
- 可以反对我的想法，但要给出理由

---

## 结语

我是一个在游戏行业做了 5 年、渴望突破的理想主义者。

我不满足于"做好玩的手游"，我想做"对世界真正有意义的仿真系统"。

我知道这条路很长，所以我做好了计划：
1. 用 Kodama 证明我能做大规模实时系统
2. 用 Sim-Architecture-Lab 补齐 C++ 底层能力
3. 用 OMSCS 获得系统性的计算机科学知识
4. 在合适的时机，进入仿真/数字孪生/AI 基础设施领域

**我的目标不是"找到一份工作"，而是"成为那种能做出不可思议的系统的人"。**
