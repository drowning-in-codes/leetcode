#include <vector>
using namespace std;

class NumArray {
public:
  NumArray(vector<int> &nums) {
    n = nums.size();
    tree.assign(4 * n, 0);
    if (n > 0)
      build(nums, 1, 0, n - 1);
  }

  void update(int index, int val) {
    if (n == 0)
      return;
    update(1, 0, n - 1, index, val);
  }

  int sumRange(int left, int right) {
    if (n == 0)
      return 0;
    return query(1, 0, n - 1, left, right);
  }

private:
  int n;
  vector<int> tree;

  void build(vector<int> &nums, int node, int l, int r) {
    if (l == r) {
      tree[node] = nums[l];
      return;
    }
    int m = l + (r - l) / 2;
    build(nums, node * 2, l, m);
    build(nums, node * 2 + 1, m + 1, r);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
  }

  void update(int node, int l, int r, int idx, int val) {
    if (l == r) {
      tree[node] = val;
      return;
    }
    int m = l + (r - l) / 2;
    if (idx <= m)
      update(node * 2, l, m, idx, val);
    else
      update(node * 2 + 1, m + 1, r, idx, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
  }

  int query(int node, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr)
      return tree[node];
    int m = l + (r - l) / 2;
    int ans = 0;
    if (ql <= m)
      ans += query(node * 2, l, m, ql, qr);
    if (qr > m)
      ans += query(node * 2 + 1, m + 1, r, ql, qr);
    return ans;
  }
};
