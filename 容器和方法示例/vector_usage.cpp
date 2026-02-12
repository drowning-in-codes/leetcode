#include <bits/stdc++.h>
using namespace std;

int main() {
  // ========== vector 基本用法 ==========
  cout << "=== vector 基本用法 ===" << endl;

  // 构造
  vector<int> v1;        // 空向量
  vector<int> v2(5);     // 5个默认值(0)
  vector<int> v3(5, 10); // 5个10
  v1 = {1, 2, 3, 4, 5};  // 初始化列表

  // 访问与修改
  cout << "v1[0] = " << v1[0] << endl; // 不检查越界
  cout << "v1.front() = " << v1.front() << endl;
  cout << "v1.back() = " << v1.back() << endl;

  v1.push_back(6); // 均摊O(1)
  v1.pop_back();   // 删除最后
  cout << "size: " << v1.size() << endl;

  // O(n)操作，性能差
  v1.insert(v1.begin() + 1, 99); // 在索引1插入99
  v1.erase(v1.begin() + 1);      // 删除索引1

  // 迭代
  cout << "遍历: ";
  for (auto x : v1)
    cout << x << " ";
  cout << endl;

  // 去重（提前排序）
  sort(v1.begin(), v1.end());
  auto it = unique(v1.begin(), v1.end());
  v1.erase(it, v1.end());

  cout << endl;

  // ========== 二维vector初始化 ==========
  cout << "=== 二维vector（DP数组） ===" << endl;
  int m = 3, n = 4;
  vector<vector<int>> dp(m, vector<int>(n, 0));

  // 修改值
  dp[0][0] = 1;
  cout << "dp[0][0] = " << dp[0][0] << endl;
  cout << "dp大小: " << dp.size() << " x " << dp[0].size() << endl;

  cout << endl;

  // ========== 常见错误 ==========
  cout << "=== 常见错误示例 ===" << endl;

  // 错误1: 使用v[i]无越界检查
  vector<int> test = {1, 2, 3};
  // int x = test[10];  // 未定义行为，可能崩溃

  // 正确: 用at()检查
  try {
    int x = test.at(10);
  } catch (...) {
    cout << "捕获越界异常" << endl;
  }

  // 错误2: erase()后迭代器失效
  vector<int> arr = {1, 2, 3, 4, 5};
  for (auto it = arr.begin(); it != arr.end();) {
    if (*it == 3) {
      it = arr.erase(it); // 正确: erase返回新迭代器
    } else {
      ++it;
    }
  }
  cout << "删除3后: ";
  for (auto x : arr)
    cout << x << " ";
  cout << endl;

  return 0;
}
