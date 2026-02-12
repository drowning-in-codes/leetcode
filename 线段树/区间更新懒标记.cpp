#include <vector>
using namespace std;

class SegTree {
public:
  SegTree(int n) : n(n), tree(4 * n, 0), lazy(4 * n, 0) {}

  void update(int l, int r, int val) { update(1, 0, n - 1, l, r, val); }
  long long query(int l, int r) { return query(1, 0, n - 1, l, r); }

private:
  int n;
  vector<long long> tree;
  vector<long long> lazy;

  void push(int node, int l, int r) {
    if (lazy[node] == 0 || l == r)
      return;
    int mid = l + (r - l) / 2;
    int lc = node * 2, rc = node * 2 + 1;
    long long v = lazy[node];
    tree[lc] += v * (mid - l + 1);
    tree[rc] += v * (r - mid);
    lazy[lc] += v;
    lazy[rc] += v;
    lazy[node] = 0;
  }

  void update(int node, int l, int r, int ql, int qr, int val) {
    if (ql <= l && r <= qr) {
      tree[node] += 1LL * val * (r - l + 1);
      lazy[node] += val;
      return;
    }
    push(node, l, r);
    int mid = l + (r - l) / 2;
    if (ql <= mid)
      update(node * 2, l, mid, ql, qr, val);
    if (qr > mid)
      update(node * 2 + 1, mid + 1, r, ql, qr, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
  }

  long long query(int node, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr)
      return tree[node];
    push(node, l, r);
    int mid = l + (r - l) / 2;
    long long ans = 0;
    if (ql <= mid)
      ans += query(node * 2, l, mid, ql, qr);
    if (qr > mid)
      ans += query(node * 2 + 1, mid + 1, r, ql, qr);
    return ans;
  }
};
