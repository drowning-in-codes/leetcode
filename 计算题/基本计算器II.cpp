#include <string>
using namespace std;

class Solution {
public:
  int calculate(string s) {
    long long num = 0;
    long long last = 0;
    long long ans = 0;
    char op = '+';

    for (int i = 0; i < (int)s.size(); ++i) {
      char c = s[i];
      if (c >= '0' && c <= '9') {
        num = num * 10 + (c - '0');
      }
      if ((c < '0' || c > '9') && c != ' ' || i == (int)s.size() - 1) {
        if (op == '+') {
          ans += last;
          last = num;
        } else if (op == '-') {
          ans += last;
          last = -num;
        } else if (op == '*') {
          last = last * num;
        } else {
          last = last / num;
        }
        op = c;
        num = 0;
      }
    }
    return (int)(ans + last);
  }
};
