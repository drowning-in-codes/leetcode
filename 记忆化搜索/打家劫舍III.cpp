#include <algorithm>
#include <unordered_map>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  int rob(TreeNode *root) { return max(dfsRob(root), dfsSkip(root)); }

private:
  unordered_map<TreeNode *, int> robMemo;
  unordered_map<TreeNode *, int> skipMemo;

  int dfsRob(TreeNode *node) {
    if (!node)
      return 0;
    if (robMemo.count(node))
      return robMemo[node];

    int ans = node->val + dfsSkip(node->left) + dfsSkip(node->right);
    robMemo[node] = ans;
    return ans;
  }

  int dfsSkip(TreeNode *node) {
    if (!node)
      return 0;
    if (skipMemo.count(node))
      return skipMemo[node];

    int leftBest = max(dfsRob(node->left), dfsSkip(node->left));
    int rightBest = max(dfsRob(node->right), dfsSkip(node->right));
    int ans = leftBest + rightBest;
    skipMemo[node] = ans;
    return ans;
  }
};
