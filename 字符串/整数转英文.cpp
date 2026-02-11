#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> units{"", "Thousand", "Million", "Billion"};
  vector<string> singles{"",        "One",       "Two",      "Three",
                         "Four",    "Five",      "Six",      "Seven",
                         "Eight",   "Nine",      "Ten",      "Eleven",
                         "Twelve",  "Thirteen",  "Fourteen", "Fifteen",
                         "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
  vector<string> tens{"",      "Ten",   "Twenty",  "Thirty", "Forty",
                      "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

  string helper(int num) {
    // 100
    string res;
    if (num >= 100) {
      res = singles[num / 100] + " Hundred " + helper(num % 100);
    } else if (num >= 20) {
      res = tens[num / 10] + " " + helper(num % 10);
    } else {
      res = singles[num] + " ";
    }
    return res;
  }
  string numberToWords(int num) {
    if (num == 0) {
      return "Zero";
    }
    // 每隔3个区分
    string res{};
    int i{};
    while (num > 0) {
      int part = num % 1000;
      res = helper(part) + units[i] + res;
      num /= 1000;
      i++;
    }
    while (!res.empty() && res.back() == ' ') {
      res.pop_back();
    }
    return res;
  }
};

int main() {
  Solution sol;
  string s;
  cout << sol.numberToWords(123);
}