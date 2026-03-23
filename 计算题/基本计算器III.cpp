#include <string>
using namespace std;

class Solution {
public:
  int calculate(string s) {
    int i = 0;
    return (int)parseExpr(s, i);
  }

private:
  long long parseExpr(const string &s, int &i) {
    long long num = 0;
    long long last = 0;
    long long ans = 0;
    char op = '+';

    while (i < (int)s.size()) {
      char c = s[i];
      if (c == ' ') {
        ++i;
        continue;
      }

      if (c >= '0' && c <= '9') {
        num = 0;
        while (i < (int)s.size() && s[i] >= '0' && s[i] <= '9') {
          num = num * 10 + (s[i] - '0');
          ++i;
        }
      } else if (c == '(') {
        ++i;
        num = parseExpr(s, i);
      }

      if (i >= (int)s.size() || s[i] == '+' || s[i] == '-' || s[i] == '*' ||
          s[i] == '/' || s[i] == ')') {
        if (op == '+') {
          ans += last;
          last = num;
        } else if (op == '-') {
          ans += last;
          last = -num;
        } else if (op == '*') {
          last = last * num;
        } else if (op == '/') {
          last = last / num;
        }

        if (i < (int)s.size() && s[i] == ')') {
          ++i;
          break;
        }

        if (i < (int)s.size()) {
          op = s[i];
          ++i;
          num = 0;
        }
      }
    }

    return ans + last;
  }
};
