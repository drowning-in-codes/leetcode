#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> res;
    stack<TreeNode *> st;
    TreeNode *cur = root;
    TreeNode *prev = nullptr;

    while (cur || !st.empty()) {
      while (cur) {
        st.push(cur);
        cur = cur->left;
      }
      TreeNode *node = st.top();
      if (!node->right || node->right == prev) {
        res.push_back(node->val);
        st.pop();
        prev = node;
      } else {
        cur = node->right;
      }
    }
    return res;
  }
};
