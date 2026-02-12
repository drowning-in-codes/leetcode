# LeetCode 容器与方法完整学习指南

本目录包含完整的容器使用教程、代码示例和最佳实践，涵盖 C++ STL 和 Java Collections。

## 📚 文件导航

### 1. **详细文档**

#### [C++常用容器与方法.md](../C++常用容器与方法.md)
- **内容**：C++ STL 所有核心容器的完整 API 参考
- **包括**：
  - vector、string、array（数据存储）
  - unordered_map、map、unordered_set、set（集合）
  - stack、queue、deque、priority_queue（高级结构）
  - sort、lower_bound、unique 等算法
- **特点**：每个容器包含使用方法、注意事项和常见陷阱
- **适用**：快速查阅容器 API 和性能特征

#### [Java常用容器与方法.md](../Java常用容器与方法.md)
- **内容**：Java Collections 完整参考
- **包括**：
  - ArrayList、LinkedList（列表）
  - HashMap、TreeMap、HashSet、TreeSet（集合）
  - ArrayDeque、PriorityQueue（队列）
  - String、StringBuilder（字符串）
  - Collections 工具类
- **特点**：对应 C++ 容器的 Java 版本，便于对比
- **适用**：Java 解题时快速查阅

#### [最佳实践与常见陷阱.md](./最佳实践与常见陷阱.md)
- **内容**：综合指南，深度讲解优化和陷阱
- **包括**：
  - 容器选择指南（什么时候用什么）
  - 常见陷阱 + 修复代码
  - 性能对比表格
  - 常用编程模式（两指针、单调栈、Dijkstra 等）
  - 快速调试技巧
- **适用**：算法课程或复杂题目的参考

---

### 2. **代码示例**

#### [vector_usage.cpp](./vector_usage.cpp)
```cpp
// 演示内容：
// - vector 的基本操作（push_back、pop_back、insert、erase）
// - 二维 vector 初始化（DP 数组）
// - 常见错误：越界访问、erase 时迭代器失效
// - 正确做法：用 at() 检查、erase 时重获迭代器

// 编译运行：
// g++ vector_usage.cpp -o vector && ./vector
```

#### [string_map_set_usage.cpp](./string_map_set_usage.cpp)
```cpp
// 演示内容：
// - string 查找、子串、比较
// - unordered_map 安全查询（count/find）
// - unordered_set 插入返回值
// - map/set 有序遍历和范围查询（lower_bound/upper_bound）
// - stack 括号匹配
// - queue BFS 遍历
// - priority_queue 大小根堆
// - sort、lower_bound、unique 算法

// 编译运行：
// g++ string_map_set_usage.cpp -o string && ./string
```

#### [JavaContainersUsage.java](./JavaContainersUsage.java)
```java
// 演示内容：
// - ArrayList 添加、删除、遍历
// - 遍历时删除的正确方式（用 Iterator）
// - String 不可变 vs StringBuilder
// - HashMap 安全查询（getOrDefault、putIfAbsent）
// - HashSet 插入重复检查
// - ArrayDeque 作为栈和队列
// - PriorityQueue 小根堆 vs 大根堆
// - TreeMap 有序和范围查询
// - Collections 工具类

// 编译运行：
// javac JavaContainersUsage.java
// java JavaContainersUsage
```

---

## 🎯 快速开始

### 对于 C++ 使用者

**第一次使用某容器时：**
1. 打开 [C++常用容器与方法.md](../C++常用容器与方法.md)
2. 查看该容器的 API 和注意事项
3. 对比 [vector_usage.cpp](./vector_usage.cpp) 或 [string_map_set_usage.cpp](./string_map_set_usage.cpp) 中的示例
4. 了解常见陷阱，避免踩坑

**调试性能问题时：**
1. 查看 [最佳实践与常见陷阱.md](./最佳实践与常见陷阱.md) 中的性能对比表
2. 检查是否选错了容器
3. 查看算法模式是否可优化

### 对于 Java 使用者

**第一次使用某容器时：**
1. 打开 [Java常用容器与方法.md](../Java常用容器与方法.md)
2. 查看该容器的方法和使用注意
3. 参考 [JavaContainersUsage.java](./JavaContainersUsage.java) 中的代码示例
4. 对比 C++ 版本理解差异

**常见陷阱对比：**
1. 字符串处理：Java 中用 StringBuilder 代替频繁 += 拼接
2. 集合遍历：用 Iterator 而不是普通循环删除
3. HashMap 返回值：get() 返回 null 而不是异常

---

## 📊 容器对比表

### 访问特性

| C++ | Java | 随机访问 | 插入删除 | 查询 | 有序 |
|-----|------|--------|--------|------|------|
| vector | ArrayList | O(1) | O(n) | O(n) | 否 |
| deque | ArrayDeque | O(1) | O(1)双端 | O(n) | 否 |
| map | TreeMap | O(log n) | O(log n) | O(log n) | 是 |
| unordered_map | HashMap | - | O(1)avg | O(1)avg | 否 |
| set | TreeSet | - | O(log n) | O(log n) | 是 |
| stack | ArrayDeque(栈) | 不支持 | O(1) | O(1) | 否 |
| queue | ArrayDeque(队列) | 不支持 | O(1) | O(1) | 否 |

---

## 🔍 按场景选择容器

### "我需要..."

| 需求 | C++ | Java | 原因 |
|------|-----|------|------|
| 快速读取任意位置 | vector | ArrayList | O(1) 索引 |
| 频繁前后插删 | deque | ArrayDeque | O(1) 两端 |
| 有序存储+范围查 | map/set | TreeMap/TreeSet | 自动排序 |
| 快速查询是否存在 | unordered_set | HashSet | O(1) 平均 |
| 统计元素频率 | unordered_map | HashMap | 键值配对 |
| 实现栈/括号匹配 | stack | ArrayDeque | LIFO 语义 |
| BFS/最短路 | queue | ArrayDeque | FIFO 语义 |
| 优先级处理 | priority_queue | PriorityQueue | 自动排序 |

---

## 💡 关键要点

### C++ 陷阱清单
- ❌ 直接访问 `v[i]` 不检查越界 → 用 `v.at(i)` 或检查大小
- ❌ `mp[key]` 自动插入默认值 → 用 `mp.count(key)` 先检查
- ❌ 遍历时直接 `v.erase()` → 用 `it = v.erase(it)` 重获迭代器
- ❌ `unique()` 只是移动 → 配合 `erase()` 才能真正删除
- ❌ `priority_queue` 无 `erase()` → 用懒删除或重建

### Java 陷阱清单
- ❌ `map.get(key)` 返回 null → 用 `getOrDefault(key, default)` 
- ❌ String 频繁 += 拼接 → 用 `StringBuilder` 代替
- ❌ 遍历时直接 `list.remove()` → 用 `Iterator.remove()`
- ❌ `==` 比较字符串 → 用 `.equals()` 比较内容
- ❌ PriorityQueue 默认小根堆 → 大根堆需指定 `(a,b)->b-a`

---

## 🚀 性能优化建议

### 时间复杂度优化顺序
1. **O(n²) → O(n log n)**：换个算法（排序、二分、堆）
2. **O(n log n) → O(n)**：用哈希表或双指针
3. **O(n) → O(1)**：空间换时间（预处理、记忆化）

### 常见优化案例
- **两数之和**：unordered_map 比双指针慢，改双指针 O(n log n) → O(n)
- **滑动窗口最大值**：队列 + 贪心 O(n) 比堆快
- **Dijkstra**：优先队列选择正确容器至关重要
- **DP**：合理选择 map vs array，避免不必要的哈希

---

## 📖 进阶学习资源

### 推荐阅读
- 《算法竞赛进阶指南》- 咨询容器选择
- C++ Reference - 查阅官方 API
- Java Collections Framework Docs - 理解设计思想

### 练习题目
- 两指针：[LeetCode 167, 125, 344](https://leetcode.com)
- 滑动窗口：[LeetCode 3, 76, 438](https://leetcode.com)
- 单调栈：[LeetCode 84, 85, 42](https://leetcode.com)
- 优先队列：[LeetCode 347, 692, 1337](https://leetcode.com)

---

## ❓ FAQ

**Q: 什么时候该用 map 而不是 unordered_map？**  
A: 需要有序遍历或范围查询时用 map；查询频繁用 unordered_map。如果哈希碰撞严重（TLE），改 map。

**Q: priority_queue 如何删除中间元素？**  
A: 无直接方法。选项：1) 懒删除（标记删除），2) 用 set 代替，3) 重建堆。

**Q: vector 可以存储自定义类吗？**  
A: 可以，容器存储的是对象副本。自定义类需定义拷贝构造函数（通常默认可用）。

**Q: ArrayList 和 LinkedList 怎么选？**  
A: 优先 ArrayList（随机访问快）。只有频繁中间删除才用 LinkedList（但实践中罕见）。考虑用 ArrayDeque。

**Q: 为什么我的 HashMap 比 array 还慢？**  
A: 可能：1) key 类型复杂（重载了 hashCode），2) 哈希碰撞多，3) 容量不足导致频繁扩容。用数组索引更快。

---

## 📝 版本信息

- **C++ 标准**：C++17 或更高
- **Java 版本**：Java 8 或更高（使用 Lambda 表达式）
- **编译测试**：g++ -std=c++17、javac 1.8+

---

**最后更新**：2024年  
**维护者**：LeetCode 刷题指南  
**贡献欢迎**：发现了新的陷阱或优化？欢迎补充！

