#include <cstdlib>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0)
      return "0";

    string res;
    long long n = numerator;
    long long d = denominator;

    if ((n < 0) ^ (d < 0))
      res.push_back('-');

    n = llabs(n);
    d = llabs(d);

    res += to_string(n / d);
    long long rem = n % d;
    if (rem == 0)
      return res;

    res.push_back('.');
    unordered_map<long long, int> seen;

    while (rem != 0) {
      if (seen.count(rem)) {
        int pos = seen[rem];
        res.insert(res.begin() + pos, '(');
        res.push_back(')');
        break;
      }
      seen[rem] = (int)res.size();
      rem *= 10;
      res.push_back(char('0' + rem / d));
      rem %= d;
    }

    return res;
  }
};
