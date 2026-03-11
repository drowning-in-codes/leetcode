#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  string decodeString(string s) {
    stack<int> cntSt;
    stack<string> strSt;
    string cur;
    int num = 0;

    for (char c : s) {
      if (c >= '0' && c <= '9') {
        num = num * 10 + (c - '0');
      } else if (c == '[') {
        cntSt.push(num);
        strSt.push(cur);
        num = 0;
        cur.clear();
      } else if (c == ']') {
        int repeat = cntSt.top();
        cntSt.pop();
        string prev = strSt.top();
        strSt.pop();
        string tmp;
        for (int i = 0; i < repeat; ++i)
          tmp += cur;
        cur = prev + tmp;
      } else {
        cur.push_back(c);
      }
    }
    return cur;
  }
};
