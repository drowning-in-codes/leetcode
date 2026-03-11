struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  void flatten(TreeNode *root) {
    TreeNode *prev = nullptr;
    dfs(root, prev);
  }

private:
  void dfs(TreeNode *node, TreeNode *&prev) {
    if (!node)
      return;
    dfs(node->right, prev);
    dfs(node->left, prev);
    node->right = prev;
    node->left = nullptr;
    prev = node;
  }
};
