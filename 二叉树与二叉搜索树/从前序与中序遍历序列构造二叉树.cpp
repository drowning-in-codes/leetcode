#include <unordered_map>
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
    unordered_map<int, int> pos;
    for (int i = 0; i < (int)inorder.size(); ++i)
      pos[inorder[i]] = i;

    int preIdx = 0;
    return dfs(preorder, 0, (int)inorder.size() - 1, preIdx, pos);
  }

private:
  TreeNode *dfs(vector<int> &preorder, int inL, int inR, int &preIdx,
                unordered_map<int, int> &pos) {
    if (inL > inR)
      return nullptr;

    int rootVal = preorder[preIdx++];
    TreeNode *root = new TreeNode(rootVal);
    int k = pos[rootVal];

    root->left = dfs(preorder, inL, k - 1, preIdx, pos);
    root->right = dfs(preorder, k + 1, inR, preIdx, pos);
    return root;
  }
};
