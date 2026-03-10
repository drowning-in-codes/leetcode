struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    int a = p->val, b = q->val;
    TreeNode *cur = root;
    while (cur) {
      if (a < cur->val && b < cur->val)
        cur = cur->left;
      else if (a > cur->val && b > cur->val)
        cur = cur->right;
      else
        return cur;
    }
    return nullptr;
  }
};
