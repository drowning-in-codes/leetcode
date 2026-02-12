# C++ LeetCode 常用容器与方法

> 面向刷题常见用法，按容器列出核心方法与常见重载。包含使用注意事项、常见陷阱和最佳实践。

## 数组与字符串

### vector
- 构造：`vector<int> v;`、`vector<int> v(n);`、`vector<int> v(n, val);`
- 访问：`v[i]`、`v.at(i)`、`v.front()`、`v.back()`
- 修改：`v.push_back(x)`、`v.pop_back()`、`v.insert(pos, x)`、`v.erase(pos)`、`v.assign(n, val)`
- 迭代：`v.begin()`、`v.end()`、`v.rbegin()`、`v.rend()`
- 大小：`v.size()`、`v.empty()`、`v.resize(n)`、`v.clear()`

**使用方法与注意事项**
- `v[i]` 不检查越界（更快），`v.at(i)` 会抛异常（更安全）
- `push_back()` 自动扩容，**均摊 O(1) 效率**。`insert()` 需要平移其他元素，**O(n) 复杂度**
- 构造多维数组用 `vector<vector<int>> dp(m, vector<int>(n, 0))`，后面的 `vector<int>(n, 0)` 必须先构造再复制
- **陷阱**：`for (auto &x : v)` 用引用可避免复制；`v[i]` 不会改变 size，但 `v.push_back()` 会
- 双指针、滑动窗口中常用 `v.erase()`，但性能较差，建议用新 vector 或单独处理

---

### string
- 构造：`string s;`、`string s(n, 'a');`、`string s("hello");`
- 访问：`s[i]`、`s.at(i)`、`s.front()`、`s.back()`
- 修改：`s.push_back(c)`、`s.pop_back()`、`s.append(str)`、`s += str`
- 子串：`s.substr(pos, len)` 返回新字符串
- 查找：`s.find(str)`、`s.rfind(str)` 返回位置，失败返回 `string::npos`
- 比较：`s.compare(str)`、`s == str`

**使用方法与注意事项**
- string 内部存储可变长数据，可视为 `vector<char>`
- `s += str` 比 `s.append(str)` 更直观，两者性能相同
- `s.find()` **返回 size_t 类型**，失败时 `== string::npos`（一个很大的无符号数）
  ```cpp
  if (s.find("ab") != string::npos) { /* 找到 */ }
  ```
- `substr()` 会创建新字符串，频繁调用性能差
- **陷阱**：`string::npos` 是 `size_t(-1)`，不能用 `int` 接收

---

### array
- 构造：`array<int, N> a;` 大小在编译期确定
- 访问：`a[i]`、`a.at(i)`、`a.front()`、`a.back()`
- 大小：`a.size()`、`a.fill(val)`

**使用方法与注意事项**
- 大小固定，栈上分配，性能优于 vector
- 适合题目输入大小确定的场景
- `at()` 检查越界，性能略低

---

## 哈希与有序集合

### unordered_map
- 插入：`mp[key] = val`、`mp.emplace(k, v)`、`mp.insert({k, v})`
- 查找：`mp.find(key)`、`mp.count(key)`
- 删除：`mp.erase(key)`
- 访问：`mp[key]`（不存在会插入默认值）、`mp.at(key)`（不存在抛异常）

**使用方法与注意事项**
- `mp[key]` 若 key 不存在会**自动插入默认值**（0/false/""/nullptr），可能改变 map 大小
- **最安全做法**：先用 `mp.count(key)` 或 `find()` 判定是否存在
  ```cpp
  if (mp.count(key)) { 
      int val = mp[key];  // 安全访问
  }
  // 或者
  auto it = mp.find(key);
  if (it != mp.end()) {
      int val = it->second;
  }
  ```
- `emplace(k, v)` 比 `insert()` 效率高（原地构造，无复制）
- **平均 O(1)**，**最坏 O(n)**（哈希碰撞）
- **陷阱**：遍历时不能修改 map 大小（会失效迭代器），可以修改 value

---

### unordered_set
- 插入：`s.insert(x)`
- 查找：`s.find(x)`、`s.count(x)`
- 删除：`s.erase(x)`

**使用方法与注意事项**
- `count()` 返回 0 或 1（集合无重复）
- `insert()` 若元素已存在不再插入，**返回 `pair<iterator, bool>`**，bool 表示插入是否成功
  ```cpp
  auto [it, inserted] = s.insert(x);  // C++17
  if (inserted) { /* 新元素 */ }
  ```
- **性能对比**：双指针往往比 unordered_set 更高效（两数之和等题目)
- 平均 O(1)，最坏 O(n)

---

### map / set
- 插入：`m[key] = val`、`m.emplace(k, v)`、`s.insert(x)`
- 查找：`m.find(k)`、`m.lower_bound(k)`、`m.upper_bound(k)`、`m.count(k)`
- 迭代：**有序遍历**（红黑树实现）
- 删除：`m.erase(k)`

**使用方法与注意事项**
- `lower_bound(k)` 返回 **≥ k 的第一个元素**的迭代器
- `upper_bound(k)` 返回 **> k 的第一个元素**的迭代器
- 适用于**需要有序遍历或快速查询范围**的场景
- 操作复杂度 **O(log n)**
- **常见用法**：
  ```cpp
  auto it = m.lower_bound(k);  // 找第一个 >= k 的
  if (it != m.end() && it->first == k) { /* 找到 k */ }
  
  // 找小于 k 的最大元素
  it = m.lower_bound(k);
  if (it != m.begin()) { 
      --it;  // it 现在指向 < k 的最大元素
  }
  ```

---

## 栈与队列

### stack
- 操作：`st.push(x)`、`st.pop()`、`st.top()`、`st.empty()`、`st.size()`

**使用方法与注意事项**
- `pop()` **不返回值**，必须先 `top()` 取值再 `pop()`
  ```cpp
  if (!st.empty()) {
      int x = st.top();
      st.pop();
  }
  ```
- **经典题目**：有效括号匹配、单调栈求下一个更大元素、表达式求值
- **陷阱**：空栈调用 `top()` 会崩溃，必须检查 `empty()`

---

### queue
- 操作：`q.push(x)`、`q.pop()`、`q.front()`、`q.back()`、`q.empty()`

**使用方法与注意事项**
- `pop()` **不返回值**，必须先 `front()` 取值再 `pop()`
- **BFS 标准写法**：
  ```cpp
  queue<pair<int,int>> q;
  q.push({start, 0});
  while (!q.empty()) {
      auto [node, dist] = q.front();
      q.pop();
      // 处理 node
  }
  ```
- **陷阱**：空队列调用 `front()` 会崩溃

---

### deque
- 操作：`dq.push_back(x)`、`dq.push_front(x)`、`dq.pop_back()`、`dq.pop_front()`
- 访问：`dq.front()`、`dq.back()`、`dq[i]`、`dq.empty()`

**使用方法与注意事项**
- 支持**前后访问与修改**，比 queue 更灵活
- 适合：滑动窗口最大值、队列+栈混合场景
- 可用作：双端队列（BFS 01 问题）、栈、队列的替代品
- **性能**：O(1) 各端访问修改，但随机访问略慢于 vector

---

### priority_queue
- 默认大根堆：`priority_queue<int> pq;`
- 小根堆：`priority_queue<int, vector<int>, greater<int>> pq;`
- 操作：`pq.push(x)`、`pq.pop()`、`pq.top()`、`pq.empty()`、`pq.size()`

**使用方法与注意事项**
- `pop()` **不返回值**，先 `top()` 后 `pop()`
- **默认大根堆**（大的元素优先）
- **小根堆写法**：`priority_queue<int, vector<int>, greater<int>>`
- **自定义类型**需要重载 `operator<` 或提供比较函数
  ```cpp
  struct Node {
      int val, idx;
      bool operator<(const Node &o) const {
          return val > o.val;  // 注意反向，因为优先队列默认反向排序
      }
  };
  priority_queue<Node> pq;
  ```
- **无 erase() 操作**，删除特定元素需要：
  - **懒删除**：标记删除，出队时检查是否被标记
  - **重建**：重新插入需要的元素
- **经典题目**：前 K 大、Dijkstra、Prim、Huffman 编码

---

## 常用算法

### 排序和二分
- 排序：`sort(v.begin(), v.end())`、`sort(v.begin(), v.end(), cmp)`
- 二分查找：`lower_bound(v.begin(), v.end(), x)`、`upper_bound(...)`
- 反转：`reverse(v.begin(), v.end())`
- 去重：`v.erase(unique(v.begin(), v.end()), v.end())`
- 累加：`accumulate(v.begin(), v.end(), 0)`

**使用方法与注意事项**
- `sort()` 内部是快速排序混合策略，复杂度 **O(n log n)**
- 自定义比较函数需要满足**严格弱序**（必须传 `<` 定义）
  ```cpp
  sort(v.begin(), v.end(), [](int a, int b) {
      return a > b;  // 降序
  });
  ```
- `lower_bound()/upper_bound()` **前提是数组有序**，返回迭代器
  ```cpp
  auto it = lower_bound(v.begin(), v.end(), x);  // >= x
  if (it != v.end() && *it == x) { /* 找到 */ }
  ```
- `unique()` **只是把重复元素移到末尾**，不真正删除，配合 `erase()` 才能删除
  ```cpp
  auto it = unique(v.begin(), v.end());
  v.erase(it, v.end());
  ```
- `accumulate()` 需要 `#include <numeric>` 头文件
- **陷阱**：`accumulate()` 第三个参数类型决定求和类型，用 `0.0` 得浮点结果
