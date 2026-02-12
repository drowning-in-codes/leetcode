#include <bits/stdc++.h>
using namespace std;

int main() {
  // ========== string 基本用法 ==========
  cout << "=== string 基本用法 ===" << endl;

  string s = "hello";
  string s2 = "world";

  // 访问
  cout << "s[0] = " << s[0] << endl;
  cout << "s.length() = " << s.length() << endl;

  // 追加
  s += " ";
  s += s2; // s = "hello world"
  cout << "s = " << s << endl;

  // 查找 - 注意返回size_t，失败返回string::npos
  size_t pos = s.find("world");
  if (pos != string::npos) {
    cout << "找到'world'在位置 " << pos << endl;
  }

  // 子串
  string sub = s.substr(6, 5); // 从位置6取5个字符
  cout << "子串: " << sub << endl;

  // 比较
  if (s != s2) {
    cout << "s 不等于 s2" << endl;
  }

  cout << endl;

  // ========== unordered_map 用法 ==========
  cout << "=== unordered_map 用法 ===" << endl;

  unordered_map<string, int> freq;

  // 插入 - 小心mp[key]会自动插入默认值
  freq["apple"]++; // 若不存在，自动插入0，再++
  freq["banana"]++;
  freq["apple"]++;

  // 安全查询方式1: count()
  if (freq.count("apple")) {
    cout << "apple出现" << freq["apple"] << "次" << endl;
  }

  // 安全查询方式2: find()
  auto it = freq.find("orange");
  if (it != freq.end()) {
    cout << "orange: " << it->second << endl;
  } else {
    cout << "orange不存在（未插入默认值）" << endl;
  }

  // 遍历
  cout << "所有元素: ";
  for (auto &p : freq) {
    cout << p.first << ":" << p.second << " ";
  }
  cout << endl;

  // emplace更高效
  freq.emplace("cherry", 3);

  cout << endl;

  // ========== unordered_set 用法 ==========
  cout << "=== unordered_set 用法 ===" << endl;

  unordered_set<int> seen;

  // 插入 - 重复不再插入
  auto ret1 = seen.insert(10);
  cout << "插入10: 成功=" << ret1.second << endl;

  auto ret2 = seen.insert(10);
  cout << "再插入10: 成功=" << ret2.second << endl; // false

  seen.insert({20, 30, 40});

  // 查找
  if (seen.count(20)) {
    cout << "20在集合中" << endl;
  }

  cout << endl;

  // ========== map/set 有序且支持范围查询 ==========
  cout << "=== map 有序和范围查询 ===" << endl;

  map<int, string> ordered;
  ordered[3] = "三";
  ordered[1] = "一";
  ordered[2] = "二";

  // 有序遍历
  cout << "有序遍历: ";
  for (auto &p : ordered) {
    cout << p.first << "-" << p.second << " ";
  }
  cout << endl;

  // lower_bound: >= k的第一个
  auto it1 = ordered.lower_bound(2);
  if (it1 != ordered.end()) {
    cout << "lower_bound(2): key=" << it1->first << endl;
  }

  // upper_bound: > k的第一个
  auto it2 = ordered.upper_bound(1);
  if (it2 != ordered.end()) {
    cout << "upper_bound(1): key=" << it2->first << endl;
  }

  cout << endl;

  // ========== stack 用法 ==========
  cout << "=== stack 用法（括号匹配示例） ===" << endl;

  stack<char> st;
  string expr = "([])";
  bool valid = true;

  for (char c : expr) {
    if (c == '(' || c == '[') {
      st.push(c);
    } else {
      if (st.empty()) {
        valid = false;
        break;
      }
      char top = st.top();
      st.pop();
      if ((c == ')' && top != '(') || (c == ']' && top != '[')) {
        valid = false;
        break;
      }
    }
  }

  if (!st.empty())
    valid = false;
  cout << expr << " 有效=" << (valid ? "yes" : "no") << endl;

  cout << endl;

  // ========== queue 用法 BFS ==========
  cout << "=== queue 用法（BFS） ===" << endl;

  queue<pair<int, int>> q;
  q.push({0, 0});

  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    cout << "处理 (" << x << ", " << y << ")" << endl;
    if (x < 2)
      q.push({x + 1, y});
    if (y < 1)
      q.push({x, y + 1});
  }

  cout << endl;

  // ========== priority_queue 用法 ==========
  cout << "=== priority_queue 用法 ===" << endl;

  // 大根堆
  priority_queue<int> maxHeap;
  maxHeap.push(5);
  maxHeap.push(10);
  maxHeap.push(3);
  cout << "大根堆堆顶: " << maxHeap.top() << endl;
  maxHeap.pop();

  // 小根堆
  priority_queue<int, vector<int>, greater<int>> minHeap;
  minHeap.push(5);
  minHeap.push(10);
  minHeap.push(3);
  cout << "小根堆堆顶: " << minHeap.top() << endl;

  cout << endl;

  // ========== 常用算法 ==========
  cout << "=== 常用算法 ===" << endl;

  vector<int> arr = {5, 2, 8, 2, 9, 1};

  // 排序
  sort(arr.begin(), arr.end());
  cout << "排序后: ";
  for (int x : arr)
    cout << x << " ";
  cout << endl;

  // 二分查找
  auto it_find = lower_bound(arr.begin(), arr.end(), 5);
  if (it_find != arr.end() && *it_find == 5) {
    cout << "找到5" << endl;
  }

  // 去重
  auto it_unique = unique(arr.begin(), arr.end());
  arr.erase(it_unique, arr.end());
  cout << "去重后: ";
  for (int x : arr)
    cout << x << " ";
  cout << endl;

  return 0;
}
