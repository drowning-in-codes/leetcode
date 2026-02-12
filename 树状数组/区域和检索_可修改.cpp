#include <vector>
using namespace std;

class NumArray {
public:
  NumArray(vector<int> &nums) : n(nums.size()), bit(n + 1, 0), arr(nums) {
    for (int i = 0; i < n; ++i)
      add(i + 1, arr[i]);
  }

  void update(int index, int val) {
    int diff = val - arr[index];
    arr[index] = val;
    add(index + 1, diff);
  }

  int sumRange(int left, int right) { return sum(right + 1) - sum(left); }

private:
  int n;
  vector<int> bit;
  vector<int> arr;

  void add(int i, int delta) {
    while (i <= n) {
      bit[i] += delta;
      i += i & -i;
    }
  }

  int sum(int i) {
    int res = 0;
    while (i > 0) {
      res += bit[i];
      i -= i & -i;
    }
    return res;
  }
};
