#include <stack>
#include <string>
using namespace std;

// 给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。
// 注意:不允许使用任何将字符串作为数学表达式计算的内置函数，比如 eval() 。
class Solution {
public:
  int calculate(string s) {
    long long ans = 0;
    long long num = 0;
    int sign = 1;
    stack<long long> st;

    for (int i = 0; i < (int)s.size(); ++i) {
      char c = s[i];
      if (c >= '0' && c <= '9') {
        num = num * 10 + (c - '0');
      } else if (c == '+') {
        ans += sign * num;
        num = 0;
        sign = 1;
      } else if (c == '-') {
        ans += sign * num;
        num = 0;
        sign = -1;
      } else if (c == '(') {
        st.push(ans);
        st.push(sign);
        ans = 0;
        sign = 1;
      } else if (c == ')') {
        ans += sign * num;
        num = 0;
        long long prevSign = st.top();
        st.pop();
        long long prevAns = st.top();
        st.pop();
        ans = prevAns + prevSign * ans;
      }
    }

    ans += sign * num;
    return (int)ans;
  }
};
