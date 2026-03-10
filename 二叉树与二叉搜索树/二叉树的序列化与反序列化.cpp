#include <queue>
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
    if (!root)
      return "#";

    queue<TreeNode *> q;
    q.push(root);
    string out;
    while (!q.empty()) {
      TreeNode *node = q.front();
      q.pop();
      if (!node) {
        out += "#,";
        continue;
      }
      out += to_string(node->val) + ",";
      q.push(node->left);
      q.push(node->right);
    }
    if (!out.empty())
      out.pop_back();
    return out;
  }

  TreeNode *deserialize(string data) {
    if (data == "#")
      return nullptr;

    vector<string> vals = split(data);
    TreeNode *root = new TreeNode(stoi(vals[0]));
    queue<TreeNode *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < (int)vals.size()) {
      TreeNode *cur = q.front();
      q.pop();

      if (vals[i] != "#") {
        cur->left = new TreeNode(stoi(vals[i]));
        q.push(cur->left);
      }
      ++i;

      if (i < (int)vals.size() && vals[i] != "#") {
        cur->right = new TreeNode(stoi(vals[i]));
        q.push(cur->right);
      }
      ++i;
    }
    return root;
  }

private:
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
    res.push_back(cur);
    return res;
  }
};
