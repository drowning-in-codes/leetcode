# Java vs C++ 数组/字符串/容器差别速查

面向同时写 Java 和 C++ 的同学，整理常见方法差别与易混点。覆盖迭代、访问、增加、删除、查找等场景。

## 1) Size vs Length

| 场景 | Java | C++ | 易混点 |
| --- | --- | --- | --- |
| 数组 | `arr.length` | `arr.size()` (vector/array) | Java 数组用 `.length`，C++ 容器用 `.size()` |
| 字符串 | `s.length()` | `s.size()` / `s.length()` | C++ 两者都可用，Java 必须方法调用 |
| 集合 | `list.size()` | `v.size()` | Java 集合是方法，C++ 是方法 |

## 2) 访问与设置

| 结构 | Java 访问 | Java 设置 | C++ 访问 | C++ 设置 | 易混点 |
| --- | --- | --- | --- | --- | --- |
| 数组 | `arr[i]` | `arr[i] = x` | `arr[i]` | `arr[i] = x` | 都是索引语法 |
| ArrayList / vector | `list.get(i)` | `list.set(i, x)` | `v[i]` | `v[i] = x` | Java 不支持 `list[i]` |
| String | `s.charAt(i)` | 不可变 | `s[i]` | `s[i] = x` 可改 | Java String 不可变 |

## 3) 增加与删除

| 结构 | Java 增加 | Java 删除 | C++ 增加 | C++ 删除 | 易混点 |
| --- | --- | --- | --- | --- | --- |
| ArrayList / vector | `list.add(x)` | `list.remove(i)` | `v.push_back(x)` | `v.erase(v.begin()+i)` | Java 删除有索引/对象重载 |
| Deque / deque | `dq.offerLast(x)` | `dq.pollFirst()` | `dq.push_back(x)` | `dq.pop_front()` | Java `poll` 返回值，C++ `pop` 不返回 |
| Stack / stack | `stack.push(x)` | `stack.pop()` | `st.push(x)` | `st.pop()` | Java pop 返回值，C++ pop 不返回 |
| PriorityQueue | `pq.offer(x)` | `pq.poll()` | `pq.push(x)` | `pq.pop()` | Java poll 返回值，C++ pop 不返回 |

## 4) 查找与存在性

| 结构 | Java | C++ | 易混点 |
| --- | --- | --- | --- |
| HashMap / unordered_map | `map.containsKey(k)` | `mp.count(k)` | Java `get` 返回 null，C++ `mp[k]` 会插入 |
| HashSet / unordered_set | `set.contains(x)` | `s.count(x)` | Java 返回 boolean，C++ 返回 0/1 |
| String | `s.indexOf(sub)` | `s.find(sub)` | Java 不存在返回 -1，C++ 返回 `string::npos` |

## 5) 迭代

| 结构 | Java | C++ | 易混点 |
| --- | --- | --- |
| List / vector | `for (int x : list)` | `for (int x : v)` | Java 删除要用迭代器，否则异常 |
| Map / unordered_map | `for (Map.Entry<K,V> e : map.entrySet())` | `for (auto &p : mp)` | Java entrySet，C++ pair |
| Set / unordered_set | `for (int x : set)` | `for (int x : s)` | 基本一致 |

## 6) 字符串可变性

| 语言 | 字符串类型 | 可变性 | 常见写法 |
| --- | --- | --- | --- |
| Java | `String` | 不可变 | 频繁拼接用 `StringBuilder` |
| C++ | `string` | 可变 | 可以 `s[i] = 'a'` |

## 7) 常见坑速记

- Java `ArrayList` 不能用 `list[i]`，必须 `get/set`。
- Java `String` 不可变，`s += "x"` 会产生新对象。
- Java `map.get(k)` 可能返回 null，优先 `getOrDefault`。
- C++ `mp[k]` 会自动插入默认值。
- C++ `stack/queue/priority_queue` 的 `pop()` 不返回值。
- Java `ArrayList.remove(int)` 和 `remove(Integer)` 重载易混淆。

## 8) 小结建议

- 写 Java：多记 `get/set/size/length`，避免用索引访问 List。
- 写 C++：多记 `size()`，注意 `map[key]` 的自动插入。
- 频繁改字符串：Java 用 `StringBuilder`，C++ 直接改 `string`。
