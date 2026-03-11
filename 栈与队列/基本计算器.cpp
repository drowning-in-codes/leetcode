#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  int calculate(string s) {
    long long ans = 0;
    int sign = 1;
    stack<long long> st;

    for (int i = 0; i < (int)s.size(); ++i) {
      char c = s[i];
      if (c >= '0' && c <= '9') {
        long long num = 0;
        while (i < (int)s.size() && s[i] >= '0' && s[i] <= '9') {
          num = num * 10 + (s[i] - '0');
          ++i;
        }
        --i;
        ans += sign * num;
      } else if (c == '+') {
        sign = 1;
      } else if (c == '-') {
        sign = -1;
      } else if (c == '(') {
        st.push(ans);
        st.push(sign);
        ans = 0;
        sign = 1;
      } else if (c == ')') {
        long long prevSign = st.top();
        st.pop();
        long long prevAns = st.top();
        st.pop();
        ans = prevAns + prevSign * ans;
      }
    }
    return (int)ans;
  }
};
