#include <algorithm>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  int maxPathSum(TreeNode *root) {
    ans = -1000000000;
    maxGain(root);
    return ans;
  }

private:
  int ans;
  int maxGain(TreeNode *node) {
    if (!node)
      return 0;
    int l = max(0, maxGain(node->left));
    int r = max(0, maxGain(node->right));
    ans = max(ans, node->val + l + r);
    return node->val + max(l, r);
  }
};
