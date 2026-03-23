#include <string>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
  string serialize(TreeNode *root) {
    string out;
    preorder(root, out);
    if (!out.empty())
      out.pop_back();
    return out;
  }

  TreeNode *deserialize(string data) {
    vector<string> vals = split(data);
    int idx = 0;
    return build(vals, idx);
  }

private:
  void preorder(TreeNode *node, string &out) {
    if (!node) {
      out += "#,";
      return;
    }
    out += to_string(node->val) + ",";
    preorder(node->left, out);
    preorder(node->right, out);
  }

  TreeNode *build(vector<string> &vals, int &idx) {
    if (idx >= (int)vals.size() || vals[idx] == "#") {
      ++idx;
      return nullptr;
    }
    TreeNode *node = new TreeNode(stoi(vals[idx++]));
    node->left = build(vals, idx);
    node->right = build(vals, idx);
    return node;
  }

  vector<string> split(const string &s) {
    vector<string> res;
    string cur;
    for (char c : s) {
      if (c == ',') {
        res.push_back(cur);
        cur.clear();
      } else {
        cur.push_back(c);
      }
    }
    if (!cur.empty() || s == "#")
      res.push_back(cur);
    return res;
  }
};
