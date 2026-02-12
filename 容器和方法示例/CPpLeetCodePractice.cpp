#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>


using namespace std;

/**
 * C++ 开发者转 Java 的 C++ 对比版本
 * 展示同一个问题在 C++ 中如何解决
 */

/** ========== 1. 容器基本操作对照 ========== */

void vectorDemo() {
  // 创建和基本操作
  vector<int> vec;

  vec.push_back(1);           // [1]
  vec.push_back(2);           // [1, 2]
  vec.insert(vec.begin(), 0); // [0, 1, 2]

  int val = vec[0];       // 获取（注意 C++ 可用 []）
  vec[1] = 99;            // 修改 [0, 99, 2]
  vec.erase(vec.begin()); // 删除 [99, 2]

  int size = vec.size();
  bool empty = vec.empty();

  // 遍历方式1：范围 for
  for (int x : vec) {
    cout << x << "\n";
  }

  // 遍历方式2：迭代器
  for (auto it = vec.begin(); it != vec.end(); it++) {
    cout << *it << "\n";
  }

  // 遍历方式3：索引
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << "\n";
  }
}

void unorderedMapDemo() {
  unordered_map<string, int> mp;

  // 添加和更新
  mp["apple"] = 1;
  mp["apple"] = 2; // 覆盖

  // 查询（⚠️ 注意 C++ 的坑）
  if (mp.count("apple")) { // 检查键存在
    int val = mp["apple"]; // 2
  }

  // ❌ 陷阱：mp["banana"] 会自动创建键且值为 0
  int val2 = mp["banana"]; // 现在 mp 中多了 "banana" → 0

  // ✅ 使用 find 更安全
  if (mp.find("cherry") != mp.end()) {
    cout << mp["cherry"] << "\n";
  }

  // 删除
  mp.erase("apple");

  // 遍历所有键
  for (auto &key : mp) {
    cout << key.first << "\n";
  }

  // 遍历所有值
  for (auto &p : mp) {
    cout << p.second << "\n";
  }

  // 遍历键值对
  for (auto &entry : mp) {
    cout << entry.first << ": " << entry.second << "\n";
  }
}

void unorderedSetDemo() {
  unordered_set<int> st;

  st.insert(1);
  st.insert(2);
  st.insert(1); // 重复，不插入

  if (st.count(1)) { // 检查存在
    cout << "存在\n";
  }

  st.erase(2);

  for (int x : st) {
    cout << x << "\n";
  }
}

void stackAndQueueDemo() {
  // 栈
  stack<int> stk;
  stk.push(1);
  stk.push(2);

  int top = stk.top(); // 查看栈顶
  stk.pop();           // ⚠️ C++ pop() 不返回值！

  bool empty = stk.empty();

  // 队列
  queue<int> q;
  q.push(1);
  q.push(2);

  int front = q.front(); // 查看队首
  q.pop();               // 出队，不返回值

  empty = q.empty();
}

void priorityQueueDemo() {
  // 最小堆
  priority_queue<int, vector<int>, greater<int>> minHeap;
  minHeap.push(3);
  minHeap.push(1);
  minHeap.push(2);
  cout << minHeap.top() << "\n"; // 1
  minHeap.pop();

  // 最大堆（默认）
  priority_queue<int> maxHeap;
  maxHeap.push(3);
  maxHeap.push(1);
  maxHeap.push(2);
  cout << maxHeap.top() << "\n"; // 3
  maxHeap.pop();
}

/** ========== 2. 字符串操作 ========== */

void stringDemo() {
  string s = "hello";

  // 长度
  int len = s.length();
  // 或者
  len = s.size();

  // 访问字符
  char c = s[0]; // 'h'
  c = s.at(0);   // 更安全

  // 子串
  string sub = s.substr(1, 2); // "el" (位置，长度)

  // 查找
  int idx = s.find("ll");     // 2
  int notFound = s.find("x"); // string::npos

  // 比较
  bool eq = (s == "hello"); // C++ 可直接用 ==

  // 大小写转换（需要手写或用 toupper/tolower）
  transform(s.begin(), s.end(), s.begin(), ::toupper);

  // 拆分（C++ 需要手写）
  vector<string> parts;
  stringstream ss("a,b,c");
  string item;
  while (getline(ss, item, ',')) {
    parts.push_back(item);
  }

  // 拼接
  string concatenated = "hello" + string(" ") + "world";
  s += "!";

  // 替换
  size_t pos = 0;
  while ((pos = s.find("ll", pos)) != string::npos) {
    s.replace(pos, 2, "LL");
    pos += 2;
  }
}

/** ========== 3. 排序与比较器 ========== */

struct Interval {
  int start, end;
  Interval(int s, int e) : start(s), end(e) {}

  // 运算符重载方式
  bool operator<(const Interval &other) const {
    if (start != other.start)
      return start < other.start;
    return end < other.end;
  }
};

void sortDemo() {
  // 基本排序
  vector<int> vec = {3, 1, 4, 1, 5};
  sort(vec.begin(), vec.end());                 // 升序
  sort(vec.begin(), vec.end(), greater<int>()); // 降序

  // 自定义对象排序
  vector<Interval> intervals;
  intervals.push_back(Interval(1, 5));
  intervals.push_back(Interval(1, 3));
  intervals.push_back(Interval(2, 4));

  // 方式1：用运算符重载
  sort(intervals.begin(), intervals.end());

  // 方式2：用 Lambda 比较
  sort(intervals.begin(), intervals.end(),
       [](const Interval &a, const Interval &b) {
         if (a.start != b.start)
           return a.start < b.start;
         return a.end < b.end;
       });
}

/** ========== 4. 数组处理 ========== */

void arrayDemo() {
  vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6};

  // 排序
  sort(arr.begin(), arr.end());

  // 填充
  fill(arr.begin(), arr.end(), 0);

  // 复制整个向量
  vector<int> copied = arr;

  // 范围复制
  vector<int> range(arr.begin() + 1, arr.begin() + 4);

  // 二分搜索
  sort(arr.begin(), arr.end());
  auto it = lower_bound(arr.begin(), arr.end(), 4);
  if (it != arr.end()) {
    cout << "找到: " << *it << "\n";
  }

  // 转为字符串（C++ 需要手写）
  cout << "[";
  for (size_t i = 0; i < arr.size(); i++) {
    cout << arr[i];
    if (i < arr.size() - 1)
      cout << ", ";
  }
  cout << "]\n";
}

/** ========== 5. 常用 LeetCode 模板 ========== */

// 模板1：频率统计
unordered_map<int, int> frequencyMap(vector<int> &nums) {
  unordered_map<int, int> freq;
  for (int x : nums) {
    freq[x]++; // ⚠️ 自动创建和默认值 0
  }
  return freq;
}

// 模板2：Top K（用堆）
vector<int> topK(vector<int> &nums, int k) {
  unordered_map<int, int> freq;
  for (int x : nums) {
    freq[x]++;
  }

  priority_queue<int, vector<int>, greater<int>> minHeap;
  for (auto &p : freq) {
    minHeap.push(p.first);
    if (minHeap.size() > k) {
      minHeap.pop();
    }
  }

  vector<int> result;
  while (!minHeap.empty()) {
    result.push_back(minHeap.top());
    minHeap.pop();
  }
  return result;
}

// 模板3：两指针
int twoPointers(vector<int> &nums, int target) {
  int left = 0, right = nums.size() - 1;
  while (left < right) {
    int sum = nums[left] + nums[right];
    if (sum == target)
      return left + right;
    else if (sum < target)
      left++;
    else
      right--;
  }
  return -1;
}

// 模板4：滑动窗口
int slidingWindow(string s, string t) {
  unordered_map<char, int> window;
  int minLen = INT_MAX;
  int left = 0;

  for (int right = 0; right < s.length(); right++) {
    window[s[right]]++;

    while (window.size() >= t.length()) {
      minLen = min(minLen, right - left + 1);
      window[s[left]]--;
      if (window[s[left]] == 0) {
        window.erase(s[left]);
      }
      left++;
    }
  }

  return minLen == INT_MAX ? -1 : minLen;
}

// 模板5：BFS
struct Node {
  int val;
  vector<Node *> neighbors;
  Node(int v) : val(v) {}
};

vector<Node *> bfs(Node *start) {
  vector<Node *> result;
  queue<Node *> q;
  unordered_set<Node *> visited;

  q.push(start);
  visited.insert(start);

  while (!q.empty()) {
    Node *node = q.front();
    q.pop();
    result.push_back(node);

    for (Node *neighbor : node->neighbors) {
      if (visited.find(neighbor) == visited.end()) {
        visited.insert(neighbor);
        q.push(neighbor);
      }
    }
  }

  return result;
}

// 模板6：DFS
void dfs(Node *node, unordered_set<Node *> &visited) {
  if (visited.count(node))
    return;
  visited.insert(node);

  for (Node *neighbor : node->neighbors) {
    dfs(neighbor, visited);
  }
}

/** ========== 6. 类型转换 ========== */

void typeConversions() {
  // int 转 string
  int num = 123;
  string numStr = to_string(num); // 123

  // string 转 int
  string numStr2 = "456";
  int parsed = stoi(numStr2); // 456

  // char 与 ASCII
  char c = 'A';
  int ascii = (int)c; // 65

  // 数字字符转数字
  char digit = '5';
  int digitVal = digit - '0'; // 5

  // 数字转字符
  int numToChar = 7;
  char digitChar = numToChar + '0'; // '7'
}

/** ========== 7. 多线程（C++11） ========== */

#include <mutex>
#include <thread>


class Counter {
private:
  int value = 0;
  mutable mutex mtx;

public:
  void increment() {
    lock_guard<mutex> lock(mtx);
    value++;
  }

  int getValue() const {
    lock_guard<mutex> lock(mtx);
    return value;
  }
};

void threadDemo() {
  // 创建线程
  thread t([]() {
    for (int i = 0; i < 5; i++) {
      cout << "线程: " << i << "\n";
    }
  });

  t.join(); // 等待线程完成
}

/** ========== 8. 常见陷阱修正 ========== */

void pitfalls() {
  // ✅ 陷阱1：map 自动创建键
  unordered_map<string, int> mp;
  // mp["key"]++;  // ❌ 如果 key 不存在，会创建 key → 0
  if (mp.count("key")) {
    mp["key"]++;
  } else {
    mp["key"] = 1;
  }
  // ✅ 或者用 find
  auto it = mp.find("key");
  if (it != mp.end()) {
    it->second++;
  }

  // ✅ 陷阱2：vector.pop_back() 不返回值
  vector<int> vec = {1, 2, 3};
  // int last = vec.pop_back();  // ❌ 错误
  int last = vec.back(); // ✅ 先获取
  vec.pop_back();        // ✅ 再删除

  // ✅ 陷阱3：queue.pop() 不返回值
  queue<int> q;
  q.push(1);
  q.push(2);
  // int first = q.pop();         // ❌ 错误
  int first = q.front(); // ✅ 先获取
  q.pop();               // ✅ 再删除

  // ✅ 陷阱4：遍历删除
  vector<int> list = {1, 2, 3, 4, 5};
  // for (int x : list) {
  //     if (x > 2) list.erase(...);  // ❌ 迭代器失效
  // }
  // ✅ 使用迭代器安全删除
  for (auto it = list.begin(); it != list.end();) {
    if (*it > 2) {
      it = list.erase(it);
    } else {
      ++it;
    }
  }
}

int main() {
  cout << "=== C++ 开发者转 Java 的 C++ 代码对比版 ===\n\n";

  cout << "1. Vector 演示\n";
  vectorDemo();
  cout << "\n2. unordered_map 演示\n";
  unorderedMapDemo();
  cout << "\n3. 字符串演示\n";
  stringDemo();
  cout << "\n4. 排序演示\n";
  sortDemo();
  cout << "\n5. 数组演示\n";
  arrayDemo();
  cout << "\n6. 类型转换\n";
  typeConversions();

  cout << "\n✅ 所有 C++ 代码演示完整！\n";

  return 0;
}
