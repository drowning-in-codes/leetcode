# C++ 开发者快速转 Java - LeetCode 面试速成版

> 针对已掌握 C++ 的开发者，快速掌握 Java 刷题和面试的核心要点。重点突出，务实导向。

---

## 1. 核心容器 API 对照速查

### 顺序容器

| 操作 | C++ (vector) | Java (ArrayList) | 关键差别 |
|-----|-------------|-----------------|--------|
| 创建 | `vector<int> v;` | `List<Integer> list = new ArrayList<>();` | Java 需要指定类型参数 |
| 添加 | `v.push_back(x)` | `list.add(x)` | 都是 O(1) 摊销 |
| 删除 | `v.erase(it)` | `list.remove(i)` | C++ 用迭代器，Java 用索引/对象 |
| 访问 | `v[i]` | `list.get(i)` | Java **不能** 用 `list[i]` |
| 修改 | `v[i] = x` | `list.set(i, x)` | 都是 O(1) |
| 大小 | `v.size()` | `list.size()` | Java 是方法！ |
| 清空 | `v.clear()` | `list.clear()` | 都是 |
| 遍历 | `for (auto x : v)` | `for (int x : list)` | 语法基本一致 |

### 集合容器

| 操作 | C++ | Java | 关键差别 |
|-----|-----|------|--------|
| 哈希表 | `unordered_map<K,V> mp;` | `Map<K,V> map = new HashMap<>();` | Java 需要 Interface 接收 |
| 添加 | `mp[k] = v` | `map.put(k, v)` | C++ 会自动插入默认值 ⚠️ |
| 查询存在性 | `mp.count(k)` | `map.containsKey(k)` | Java 更明确 |
| 获取值 | `mp[k]` | `map.get(k)` | Java `get(k)` 返回 null |
| 安全获取 | 无 | `map.getOrDefault(k, def)` | Java 更安全 |
| 哈希集 | `unordered_set<int> s;` | `Set<Integer> set = new HashSet<>();` | 同上 |
| 查询元素 | `s.count(x)` | `set.contains(x)` | Java 返回 boolean |
| 有序集 | `map<K,V>` | `Map<K,V> map = new TreeMap<>();` | 都用红黑树 |
| 范围查询 | `mp.lower_bound(k)` | `map.tailMap(k)` | Java 用 tailMap/headMap |

### 栈和队列

| 操作 | C++ | Java | 关键差别 |
|-----|-----|------|--------|
| 栈 | `stack<int> st;` | `Deque<Integer> st = new ArrayDeque<>();` | Java 推荐用 Deque 代替 Stack |
| 入栈 | `st.push(x)` | `st.push(x)` | 一致 |
| 出栈 | `st.pop()` | `st.pop()` | **C++ pop() 不返回值** ⚠️ |
| 栈顶 | `st.top()` | `st.peek()` | 不同方法名 |
| 队列 | `queue<int> q;` | `Deque<Integer> q = new ArrayDeque<>();` | Java 也用 Deque |
| 入队 | `q.push(x)` | `q.offer(x)` | 名字不同 |
| 出队 | `q.pop()` | `q.poll()` | **Java poll() 返回值** ✅ |
| 队首 | `q.front()` | `q.peek()` | 不同方法名 |
| 优先队列 | `priority_queue<int> pq;` | `PriorityQueue<Integer> pq = new PriorityQueue<>();` | 默认都是最小堆 |
| 大根堆 | `greater<int>` | `(a,b) -> b - a` | Java 用比较器 |

---

## 2. 字符串操作对照

### 常见操作

| 操作 | C++ | Java | 陷阱 |
|-----|-----|------|------|
| 创建 | `string s = "hello";` | `String s = "hello";` | Java String 不可变！ |
| 长度 | `s.length()` / `s.size()` | `s.length()` | Java 是方法，C++ 两者都可 |
| 访问 | `s[i]` | `s.charAt(i)` | Java 必须用方法 |
| 修改字符 | `s[i] = 'x'` | `不能` | Java String 不可变，用 StringBuilder |
| 子串 | `s.substr(pos, len)` | `s.substring(pos, end)` | Java 是 [pos, end)，不是长度 |
| 查找 | `s.find(sub)` | `s.indexOf(sub)` | C++ 返回 npos，Java 返回 -1 |
| 拼接 | `s + "x"` / `s.append()` | `s + "x"` | 都可以，但频繁拼接用 StringBuilder |
| 拆分 | `istringstream` / 手写 | `s.split()` | Java 更方便 |
| 比较 | `s == t` | `s.equals(t)` | Java `==` 比较引用！ |
| 转大写 | 手写 | `s.toUpperCase()` | Java 有内置方法 |
| 转小写 | 手写 | `s.toLowerCase()` | Java 有内置方法 |

### 字符串与数组转换

```java
// 字符串转字符数组
String s = "hello";
char[] chars = s.toCharArray();

// 字符数组转字符串
String s2 = new String(chars);

// 字符串转 int
int num = Integer.parseInt("123");

// int 转字符串
String str = String.valueOf(456);

// 字符串转 List<String>（常用于分组）
List<String> parts = Arrays.asList(s.split(","));
```

---

## 3. 排序与比较器

### 基础排序

```cpp
// C++ 排序
vector<int> v = {3, 1, 4, 1, 5};
sort(v.begin(), v.end());                    // 升序
sort(v.begin(), v.end(), greater<int>());    // 降序
```

```java
// Java 排序
int[] arr = {3, 1, 4, 1, 5};
Arrays.sort(arr);                            // 升序

List<Integer> list = new ArrayList<>(Arrays.asList(3, 1, 4, 1, 5));
Collections.sort(list);                      // 升序
Collections.sort(list, Collections.reverseOrder());  // 降序
```

### 自定义比较器

```java
// 按对象的某个属性排序
class Person {
    int age;
    String name;
}

List<Person> people = new ArrayList<>();

// 方法1：Lambda 表达式（推荐）
Collections.sort(people, (a, b) -> a.age - b.age);

// 方法2：Comparator 接口
Collections.sort(people, new Comparator<Person>() {
    public int compare(Person a, Person b) {
        return a.age - b.age;
    }
});

// 方法3：List 自带 sort
people.sort((a, b) -> b.age - a.age);  // 降序
```

### 优先队列中的比较器

```java
// 小根堆（默认）
PriorityQueue<Integer> minHeap = new PriorityQueue<>();

// 大根堆
PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> b - a);

// 自定义对象的大根堆
class Node {
    int val, idx;
}
PriorityQueue<Node> pq = new PriorityQueue<>((a, b) -> b.val - a.val);
```

---

## 4. 数组处理

### 数组声明和初始化

```java
// 一维数组
int[] arr = new int[10];           // 默认初始化为 0
int[] arr2 = {1, 2, 3};
int[] arr3 = new int[]{4, 5, 6};

// 二维数组
int[][] matrix = new int[m][n];    // 默认初始化为 0
int[][] matrix2 = {{1, 2}, {3, 4}};

// 数组长度
int len = arr.length;              // 数组是 .length（属性，不是方法！）
```

### 常用 Arrays 工具类

```java
int[] arr = {4, 1, 3, 2};

// 排序
Arrays.sort(arr);                              // O(n log n)

// 填充
Arrays.fill(arr, 0);                           // 全部设为 0

// 复制
int[] copy = Arrays.copyOf(arr, arr.length);

// 范围复制
int[] range = Arrays.copyOfRange(arr, 1, 3);  // [1, 3)

// 二分搜索（前提排序）
int idx = Arrays.binarySearch(arr, 3);

// 转为列表
List<Integer> list = new ArrayList<>(Arrays.asList(1, 2, 3));

// 转为字符串
String str = Arrays.toString(arr);            // "[4, 1, 3, 2]"
```

### 数组和 List 互转

```java
// 数组 → List（推荐）
Integer[] boxedArr = {1, 2, 3};
List<Integer> fromArray = new ArrayList<>(Arrays.asList(boxedArr));

// List → 数组
List<Integer> list = new ArrayList<>();
list.add(1); list.add(2); list.add(3);
Integer[] toArray = list.toArray(new Integer[0]);

// 原始类型数组 → List（需要装箱）
int[] primitiveArr = {1, 2, 3};
List<Integer> boxedList = new ArrayList<>();
for (int x : primitiveArr) boxedList.add(x);

// Stream 方式（Java 8+）
Integer[] arr = primitiveArr.stream().boxed().toArray(Integer[]::new);
```

---

## 5. 必背 Java 集合 API 名称

### 一览表

| 功能 | C++ | Java | 必背度 |
|-----|-----|------|-------|
| 大小 | `.size()` | `.size()` **⭐** | 100% |
| 是否为空 | `.empty()` | `.isEmpty()` **⭐** | 100% |
| 添加 | `.push_back()` | `.add()` **⭐** | 100% |
| 删除 | `.erase()` | `.remove()` **⭐** | 100% |
| 清空 | `.clear()` | `.clear()` **⭐** | 100% |
| 包含 | `.count()` / `.find()` | `.contains()` **⭐** | 100% |
| 获取 | `[i]` / `.at(i)` | `.get(i)` **⭐** | 100% |
| 设置 | `[i] = x` | `.set(i, x)` **⭐** | 100% |
| 键值对 | `.begin()` | `.entrySet()` | 90% |
| 迭代 | `for (auto x : v)` | `for (Type x : collection)` **⭐** | 100% |

### 集合特定 API

```java
// Map 专有
map.put(k, v);                     // 添加/更新
map.get(k);                        // 获取，不存在返回 null
map.getOrDefault(k, defaultVal);   // 安全获取
map.containsKey(k);                // 判断键存在
map.keySet();                       // 所有键
map.values();                       // 所有值
map.entrySet();                     // 键值对集合

// Set 专有
set.add(x);                        // 返回 boolean（是否新添加）
set.contains(x);                   // 判断存在
set.remove(x);                     // 删除

// List 专有
list.add(idx, x);                  // 在指定位置插入
list.remove(idx);                  // 按索引删除
list.remove(obj);                  // 按对象删除（删第一个）
list.indexOf(obj);                 // 返回索引，不存在返回 -1
list.subList(from, to);            // 返回子列表视图
list.sort(cmp);                    // 排序（Java 8+）
```

---

## 6. 遍历删除陷阱（易犯错）

### ❌ 错误做法

```java
// 直接删除会导致异常
for (int x : list) {
    if (x > 5) list.remove(x);    // ConcurrentModificationException！
}

// 或者跳过元素
for (int i = 0; i < list.size(); i++) {
    if (list.get(i) > 5) list.remove(i);  // i++ 后会跳过下一个
}
```

### ✅ 正确做法

```java
// 方法1：用迭代器（标准）
Iterator<Integer> it = list.iterator();
while (it.hasNext()) {
    int x = it.next();
    if (x > 5) it.remove();        // 安全删除
}

// 方法2：倒序遍历
for (int i = list.size() - 1; i >= 0; i--) {
    if (list.get(i) > 5) list.remove(i);
}

// 方法3：创建新列表
List<Integer> newList = new ArrayList<>();
for (int x : list) {
    if (x <= 5) newList.add(x);
}
```

---

## 7. JVM 基础速知

### 内存结构

```
JVM 内存
├── 栈（Stack）               - 线程私有
│   ├── 方法调用栈帧
│   ├── 局部变量
│   └── 引用（不是对象本身）
│
├── 堆（Heap）              - 所有线程共享 【GC 发生地】
│   ├── 对象实例
│   ├── 数组元素
│   └── 引用指向的真实数据
│
├── 方法区（Method Area）   - 共享
│   ├── 类结构
│   ├── 常量池
│   ├── 静态变量
│   └── 代码
│
└── 程序计数器
```

### 垃圾回收（GC）

```java
// GC 何时触发
- 堆满了
- 显式调用 System.gc()（不推荐）
- 自动触发（基于 GC 算法）

// 对象何时被 GC
- 没有引用指向它
- System.gc() 运行
- JVM 退出

// 内存泄漏常见原因
- 静态集合持有引用不释放
- 监听器/回调没有反注册
- 循环引用
```

### 类加载过程

```
源代码(.java) 
    ↓ 编译
字节码(.class)
    ↓ 类加载
运行时数据
    ↓ 验证 + 准备 + 解析（链接）
    ↓ 初始化（执行 static 块）
就绪使用
```

---

## 8. 多线程基础速知

### Thread 基础

```java
// 创建线程方式1：继承 Thread
class MyThread extends Thread {
    public void run() {
        System.out.println("线程执行");
    }
}
MyThread t = new MyThread();
t.start();  // 重要：是 start，不是 run！

// 创建线程方式2：实现 Runnable（推荐）
Thread t = new Thread(() -> {
    System.out.println("线程执行");
});
t.start();

// 常用方法
Thread.currentThread();        // 当前线程
Thread.sleep(1000);           // 睡眠 1000ms
t.join();                     // 等待 t 完成
t.setPriority(10);            // 优先级 1-10
t.setName("myThread");        // 设置名称
t.isDaemon(true);             // 守护线程
```

### 数据竞争与 volatile

```java
// 问题：多线程访问共享变量
class Counter {
    private int count = 0;  // 不同线程看到值不同步
    
    public void increment() { count++; }  // 非原子操作
    public int getCount() { return count; }
}

// 解决方案1：volatile（保证可见性）
class Counter {
    private volatile int count = 0;
}

// volatile 作用
- 每次读都从主内存读
- 每次写都立即写回主内存
- ✅ 保证可见性
- ❌ 不保证原子性（count++ 仍不安全）
```

### 锁与 synchronized

```java
// 方式1：同步方法
class Counter {
    private int count = 0;
    
    public synchronized void increment() {
        count++;  // 现在是原子的
    }
    
    public synchronized int getCount() {
        return count;
    }
}

// 方式2：同步代码块
class Counter {
    private int count = 0;
    private Object lock = new Object();
    
    public void increment() {
        synchronized (lock) {
            count++;
        }
    }
}

// synchronized 作用
- ✅ 保证原子性
- ✅ 保证可见性（加锁/解锁时）
- ❌ 性能开销大
```

### 高级：AtomicInteger（比 synchronized 快）

```java
import java.util.concurrent.atomic.*;

AtomicInteger count = new AtomicInteger(0);
count.incrementAndGet();       // 原子++
count.getAndAdd(5);            // 原子加 5，返回旧值
count.compareAndSet(0, 1);     // 原子比较交换
```

---

## 9. 高频面试代码片段速记

### 遍历 HashMap

```java
Map<String, Integer> map = new HashMap<>();

// 方式1：只遍历键
for (String key : map.keySet()) {
    System.out.println(key);
}

// 方式2：只遍历值
for (Integer val : map.values()) {
    System.out.println(val);
}

// 方式3：遍历键值对（最常用）
for (Map.Entry<String, Integer> entry : map.entrySet()) {
    String key = entry.getKey();
    Integer val = entry.getValue();
}
```

### 遍历二维数组

```java
int[][] matrix = {{1, 2}, {3, 4}};

// 方式1：普通循环
for (int i = 0; i < matrix.length; i++) {
    for (int j = 0; j < matrix[i].length; j++) {
        System.out.println(matrix[i][j]);
    }
}

// 方式2：增强 for
for (int[] row : matrix) {
    for (int val : row) {
        System.out.println(val);
    }
}
```

### 排序自定义对象

```java
class Interval {
    int start, end;
    Interval(int s, int e) { start = s; end = e; }
}

List<Interval> intervals = new ArrayList<>();
// ... 填充

// 按 start 升序，若相同按 end 降序
Collections.sort(intervals, (a, b) -> {
    if (a.start != b.start) return a.start - b.start;
    return b.end - a.end;
});
```

---

## 10. 速成刷题清单

### Week 1：打好基础
- [ ] 掌握 ArrayList / HashMap / HashSet API（20道热身题）
- [ ] 理解 String 不可变性与 StringBuilder（5道字符串题）
- [ ] 学会自定义比较器（5道排序题）

### Week 2：标准算法
- [ ] BFS（用 Queue / Deque）
- [ ] DFS（用 Stack / 递归）
- [ ] 二分查找（用 Arrays.binarySearch）
- [ ] 滑动窗口（用 HashMap + 两指针）

### Week 3：深度算法
- [ ] 动态规划
- [ ] 图论（Dijkstra / Union-Find）
- [ ] 贪心

### Week 4：优化与细节
- [ ] 性能优化（时空权衡）
- [ ] 多线程题目（若面试考）
- [ ] 模拟面试 5 道混合题

---

## 11. 最常踩的坑排行榜

🥇 **第1名**：`ArrayList` 用索引访问
```java
list[i] = x;      // ❌ 编译错误
list.set(i, x);   // ✅ 正确
```

🥈 **第2名**：`map[key]` 自动插入（C++ 风格）
```cpp
mp[key]++;        // C++ ✅ 会创建键
```
```java
map.get(key)++;   // Java ❌ NPE，因为 get 返回 null
map.getOrDefault(key, 0)++;  // ✅ 正确
```

🥉 **第3名**：`String` 用 `==` 比较
```java
s == t;           // ❌ 比较引用
s.equals(t);      // ✅ 比较内容
```

4️⃣ **第4名**：数组长度是属性，集合是方法
```java
arr.length;       // ✅ 数组
list.size();      // ✅ 集合（不是 .size）
```

5️⃣ **第5名**：`PriorityQueue` 默认小根堆
```java
pq = new PriorityQueue<>();              // 小根堆
pq = new PriorityQueue<>((a,b)->b-a);   // 大根堆
```

---

## 12. 快速参考卡片

### 一键复制代码模板

```java
// 模板1：LeetCode 两层循环题
int[][] matrix = {};
for (int i = 0; i < matrix.length; i++) {
    for (int j = 0; j < matrix[i].length; j++) {
        // 处理
    }
}

// 模板2：HashMap 频率统计
Map<Integer, Integer> freq = new HashMap<>();
for (int x : nums) {
    freq.put(x, freq.getOrDefault(x, 0) + 1);
}

// 模板3：优先队列（Top K）
PriorityQueue<Integer> minHeap = new PriorityQueue<>();
for (int x : nums) {
    minHeap.offer(x);
    if (minHeap.size() > k) minHeap.poll();
}

// 模板4：BFS
Queue<Node> q = new LinkedList<>();
Set<Node> visited = new HashSet<>();
q.offer(start);
visited.add(start);
while (!q.isEmpty()) {
    Node node = q.poll();
    for (Node neighbor : node.neighbors) {
        if (!visited.contains(neighbor)) {
            visited.add(neighbor);
            q.offer(neighbor);
        }
    }
}
```

---

## 总结：最少需要熟悉的 API

| 集合 | 必背方法 |
|------|--------|
| ArrayList | add, get, set, remove, size, isEmpty, clear |
| HashMap | put, get, getOrDefault, containsKey, keySet, entrySet |
| HashSet | add, contains, remove, size |
| PriorityQueue | offer, poll, peek, isEmpty |
| Stack / Queue | 用 Deque: push, pop, offer, poll, peek |
| String | length, charAt, substring, indexOf, equals, split |
| Arrays | sort, fill, copyOf, binarySearch, asList, toString |

**核心建议**：
1. API 名称靠多写代码自然记住（1-2 周）
2. JVM 和多线程是面试加分项（理论理解即可）
3. 前 100 道题用 ArrayList + HashMap + PriorityQueue 足以
4. 比较器随时查，不用死记

**转换时间估计**：
- 语言语法：1-2 周
- 常用 API：2-3 周
- 算法适配：1-2 周
- **总计：1 个月达到 C++ 水平**

