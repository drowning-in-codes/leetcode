#include <climits>
#include <stack>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  bool isValidBST(TreeNode *root) {
    stack<TreeNode *> st;
    TreeNode *cur = root;
    long long prev = (long long)LLONG_MIN;
    bool hasPrev = false;

    while (cur || !st.empty()) {
      while (cur) {
        st.push(cur);
        cur = cur->left;
      }
      cur = st.top();
      st.pop();

      if (hasPrev && cur->val <= prev)
        return false;
      prev = cur->val;
      hasPrev = true;

      cur = cur->right;
    }
    return true;
  }
};
