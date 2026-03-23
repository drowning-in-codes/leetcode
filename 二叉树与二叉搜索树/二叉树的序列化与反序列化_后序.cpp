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
    postorder(root, out);
    if (!out.empty())
      out.pop_back();
    return out;
  }

  TreeNode *deserialize(string data) {
    vector<string> vals = split(data);
    int idx = (int)vals.size() - 1;
    return build(vals, idx);
  }

private:
  void postorder(TreeNode *node, string &out) {
    if (!node) {
      out += "#,";
      return;
    }
    postorder(node->left, out);
    postorder(node->right, out);
    out += to_string(node->val) + ",";
  }

  TreeNode *build(vector<string> &vals, int &idx) {
    if (idx < 0 || vals[idx] == "#") {
      --idx;
      return nullptr;
    }
    TreeNode *node = new TreeNode(stoi(vals[idx--]));
    node->right = build(vals, idx);
    node->left = build(vals, idx);
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
