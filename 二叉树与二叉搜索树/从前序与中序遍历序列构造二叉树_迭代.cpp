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
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.empty())
      return nullptr;

    TreeNode *root = new TreeNode(preorder[0]);
    stack<TreeNode *> st;
    st.push(root);
    int inIdx = 0;

    for (int i = 1; i < (int)preorder.size(); ++i) {
      int curVal = preorder[i];
      TreeNode *node = st.top();

      if (node->val != inorder[inIdx]) {
        node->left = new TreeNode(curVal);
        st.push(node->left);
      } else {
        while (!st.empty() && st.top()->val == inorder[inIdx]) {
          node = st.top();
          st.pop();
          ++inIdx;
        }
        node->right = new TreeNode(curVal);
        st.push(node->right);
      }
    }

    return root;
  }
};
