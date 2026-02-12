# Java LeetCode 常用容器与方法

> 面向刷题常见用法，按容器列出核心方法与常见重载。包含使用注意事项、常见陷阱和最佳实践。

## 数组与字符串

### 数组
- 声明：`int[] a = new int[n];`、`int[][] g = new int[m][n];`
- 长度：`a.length`
- 工具类：`Arrays.sort(a)`、`Arrays.fill(a, val)`、`Arrays.copyOf(a, newLen)`

**使用方法与注意事项**
- 数组大小固定，栈上分配（基本类型）或堆上引用（对象）
- `Arrays.sort()` 对基本类型用快排，对对象用归并排，**O(n log n)**
- **二维数组初始化** `int[][] g = new int[m][n]` 自动初始化为 0
- `System.arraycopy()` 高效复制：`System.arraycopy(src, srcPos, dst, dstPos, len)`

---

### String
- 访问：`s.charAt(i)`、`s.length()`
- 子串：`s.substring(begin, end)` **end 不含**（[begin, end)）
- 查找：`s.indexOf(str)`、`s.lastIndexOf(str)`、`s.indexOf(c, fromIdx)`
- 比较：`s.equals(t)`、`s.compareTo(t)`、`s.contains(str)`
- 操作：`s.toCharArray()`、`s.split(regex)`、`s.replace(old, new)`

**使用方法与注意事项**
- `String` **不可变**，每次修改创建新对象，频繁修改性能差
- `s.substring()` 返回 **[begin, end)** 新字符串，不改变原字符串
- `indexOf()` 找不到返回 **-1**（不是异常）
  ```java
  if (s.indexOf("ab") != -1) { /* 找到 */ }
  ```
- `s.split(regex)` 返回数组，**正则表达式需转义**（如 `"\\."`）
- **陷阱**：`equals()` 和 `==` 不同，`==` 比较引用，`equals()` 比较内容

---

### StringBuilder
- 操作：`sb.append(x)`、`sb.setCharAt(i, c)`、`sb.charAt(i)`
- 子串：`sb.substring(begin, end)`（与 String 同）
- 其他：`sb.reverse()`、`sb.length()`、`sb.toString()`、`sb.insert(idx, x)`

**使用方法与注意事项**
- `StringBuilder` **可变**，适合频繁修改字符串
- `sb.append()` 返回 `StringBuilder` 本身，支持链式调用
  ```java
  String result = sb.append("a").append("b").toString();
  ```
- `append()` 支持多种类型（int、boolean、等）
- 不是线程安全的；`StringBuffer` 是线程安全版本（性能低）
- **经典用法**：字符串构建、回文判定中用 `sb.reverse()`

---

## List 与集合

### ArrayList
- 构造：`List<Integer> list = new ArrayList<>();`、`new ArrayList<>(capacity)`
- 访问：`list.get(i)`、`list.set(i, val)`
- 修改：`list.add(val)`、`list.add(idx, val)`、`list.remove(idx)`、`list.remove(obj)`、`list.clear()`
- 大小：`list.size()`、`list.isEmpty()`
- 其他：`list.contains(obj)`、`list.indexOf(obj)`、`list.toArray()`

**使用方法与注意事项**
- **动态数组**，自动扩容（1.5 倍），**均摊 O(1)** 追加性能
- 随机访问 **O(1)**（索引访问）
- 中间插入/删除 **O(n)**（需要平移）
- `remove(idx)` 删除索引处元素；`remove(obj)` 删除第一个等于 obj 的元素
- **细节**：`list.contains()` 用 `equals()` 比较，自定义类需重载 `equals()` 和 `hashCode()`
- **陷阱**：遍历时删除用迭代器 `iterator.remove()`，不能用 `list.remove()`（会跳元素或异常）

---

### LinkedList
- 作为队列：`addLast(x)`、`pollFirst()`、`peekFirst()`
- 作为双端队列：`addFirst(x)`、`removeLast()`、`removeFirst()`
- 访问：`getFirst()`、`getLast()`
- 其他：`size()`、`isEmpty()`、`clear()`

**使用方法与注意事项**
- **链表结构**，前后插入删除 **O(1)**，随机访问 **O(n)**
- 不适合频繁随机访问（题目中罕见用到）
- **通常用 ArrayDeque 替代**（性能更好）
- `pollFirst()` 删不到时返回 null；`removeFirst()` 删不到时抛异常

---

## 栈与队列

### ArrayDeque（推荐替代品）
- 栈：`push(x)`、`pop()`、`peek()`、`isEmpty()`
- 队列：`offer(x)`（addLast）、`poll()`（removeFirst）、`peek()`（peekFirst）
- 双端：`offerFirst(x)`、`offerLast(x)`、`pollFirst()`、`pollLast()`、`peekFirst()`、`peekLast()`

**使用方法与注意事项**
- **双端队列**，前后操作都 **O(1)**
- **比 Stack 和 Queue 类性能好**（推荐用 ArrayDeque）
- 作**栈**用：`push(x)/pop()/peek()`
- 作**队列**用：`offer(x)/poll()/peek()`
- 作**双端队列**用：前后操作都支持
- **陷阱**：`poll()` 删不到返回 null；`remove()` 删不到抛异常

### PriorityQueue
- 默认小根堆：`PriorityQueue<Integer> pq = new PriorityQueue<>();`
- 大根堆：`new PriorityQueue<>((a, b) -> b - a)`、`new PriorityQueue<>(Collections.reverseOrder())`
- 操作：`pq.offer(x)`、`pq.poll()`、`pq.peek()`、`pq.isEmpty()`、`pq.size()`

**使用方法与注意事项**
- **默认小根堆**（小元素优先）
- **大根堆写法**：提供比较器反向排序
  ```java
  PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
  // 或用
  PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
  ```
- 自定义对象实现 `Comparator`
  ```java
  PriorityQueue<Node> pq = new PriorityQueue<>((a, b) -> a.pri - b.pri);
  ```
- **poll() 返回并删除堆顶**；`peek()` 只查看
- **无 remove(obj)** 操作，删除特定元素需要：
  - 用懒删除（外部记录删除标记）
  - 或用其他数据结构
- **经典题目**：前 K 大、Dijkstra、Prim、合并有序数组

---

## Hash 与有序集合

### HashMap
- 插入/更新：`map.put(k, v)`、`map.putIfAbsent(k, v)`、`map.putAll(other)`
- 查询：`map.get(k)`、`map.getOrDefault(k, def)`
- 判定：`map.containsKey(k)`、`map.containsValue(v)`
- 删除：`map.remove(k)`、`map.clear()`
- 大小：`map.size()`、`map.isEmpty()`

**使用方法与注意事项**
- **哈希表**，平均 **O(1)**，最坏 **O(n)**
- `get()` 不存在返回 **null**，用 `getOrDefault()` 避免 null 检查
  ```java
  int count = map.getOrDefault(key, 0);
  map.put(key, count + 1);
  ```
- `putIfAbsent()` 原子性设置，**key 不存在时才插入**
  ```java
  map.putIfAbsent(key, new ArrayList<>()).add(value);  // 链式调用
  ```
- **遍历**：
  ```java
  for (int key : map.keySet()) { }
  for (int val : map.values()) { }
  for (Map.Entry<Integer, Integer> e : map.entrySet()) {
      int k = e.getKey();
      int v = e.getValue();
  }
  ```
- **陷阱**：`get(null)` 可行（允许 null key），但往往不是题意

---

### HashSet
- 操作：`set.add(x)`、`set.contains(x)`、`set.remove(x)`、`set.clear()`
- 大小：`set.size()`、`set.isEmpty()`
- 遍历：`for (int x : set) { }`

**使用方法与注意事项**
- **哈希集合**，平均 **O(1)** 操作
- `add()` 插入成功返回 true，已存在返回 false
- 创建自定义对象集合需重载 `equals()` 和 `hashCode()`
- **性能对比**：双指针往往比 HashSet 更高效（两数之和等）

---

### TreeMap / TreeSet
- 操作：`map.put(k, v)`、`map.get(k)`、`map.remove(k)`
- 有序查询：`map.firstKey()`、`map.lastKey()`、`map.lowerKey(k)`、`map.higherKey(k)`
- 范围查询：`map.subMap(fromKey, toKey)`（**[from, to)** 半开区间）
- 迭代：自动有序遍历

**使用方法与注意事项**
- **红黑树**，所有操作 **O(log n)**
- `lowerKey(k)` 返回 **< k 的最大键**；`higherKey(k)` 返回 **> k 的最小键**
- `firstKey()/lastKey()` 树为空抛异常，用 `firstEntry()` 返回 Entry 或 null
- `subMap()` 返回视图（不独立复制）
- **应用场景**：需要有序遍历、范围查询、前驱/后继查询

---

## 常用工具

### 排序和查找
- List 排序：`Collections.sort(list)`、`Collections.sort(list, cmp)`、`list.sort(cmp)`
- 二分搜索：`Collections.binarySearch(list, key)` 返回索引，无则返回 -(插入位置+1)
- 数组排序：`Arrays.sort(arr)`、`Arrays.sort(arr, cmp)`

**使用方法与注意事项**
- `Collections.sort()` 和 `list.sort()` 功能同，后者是 **Java 8+** 方法
- **二分查找前提**：列表已排序，返回值为非负表示找到，负数表示未找到
  ```java
  int idx = Collections.binarySearch(list, key);
  if (idx >= 0) { /* 找到 */ }
  ```
- 自定义比较器：`Collections.sort(list, (a, b) -> b - a);`（降序）
- `Arrays.sort()` 对基本类型用快排，引用类型用 TimSort，性能 **O(n log n)**

---

### 其他工具
- 反转：`Collections.reverse(list)`
- 打乱：`Collections.shuffle(list)`
- 最值：`Collections.max(list)`、`Collections.min(list)`
- 求和/其他：需用流 `list.stream().mapToInt(Integer::intValue).sum()`
