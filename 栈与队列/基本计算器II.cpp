#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  int calculate(string s) {
    stack<int> st;
    char op = '+';
    long long num = 0;

    for (int i = 0; i <= (int)s.size(); ++i) {
      char c = (i == (int)s.size()) ? '+' : s[i];
      if (c == ' ')
        continue;
      if (c >= '0' && c <= '9') {
        num = num * 10 + (c - '0');
        continue;
      }

      if (op == '+')
        st.push((int)num);
      else if (op == '-')
        st.push((int)-num);
      else {
        int top = st.top();
        st.pop();
        if (op == '*')
          st.push(top * (int)num);
        else
          st.push(top / (int)num);
      }
      op = c;
      num = 0;
    }

    int ans = 0;
    while (!st.empty()) {
      ans += st.top();
      st.pop();
    }
    return ans;
  }
};
