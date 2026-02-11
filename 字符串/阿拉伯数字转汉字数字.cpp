// 11234 -> 一万一千二百三十四 假设小于INT_MAX
// 10024 ->一万零二十四
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

#include <algorithm>
#include <vector>


std::u16string arToCn(long long n) {
  if (n == 0)
    return u"零";

  std::vector<char16_t> digits = {u'零', u'一', u'二', u'三', u'四',
                                  u'五', u'六', u'七', u'八', u'九'};
  std::vector<char16_t> units = {u' ', u'十', u'百', u'千'};
  std::vector<char16_t> bigUnits = {u' ', u'万', u'亿'};

  std::u16string res = u"";
  int bigUnitIdx = 0;

  while (n > 0) {
    int section = n % 10000;
    std::u16string sectionStr = u"";
    bool zeroFlag = true; // 用于处理连续的零

    for (int i = 0; i < 4; ++i) {
      int d = section % 10;
      if (d == 0) {
        if (!zeroFlag) {
          zeroFlag = true;
          sectionStr = digits[0] + sectionStr;
        }
      } else {
        zeroFlag = false;
        std::u16string temp = u"";
        temp += digits[d];
        if (i > 0)
          temp += units[i];
        sectionStr = temp + sectionStr;
      }
      section /= 10;
    }

    // 加上大单位（万/亿）
    if (bigUnitIdx > 0 && !sectionStr.empty()) {
      sectionStr += bigUnits[bigUnitIdx];
    }
    res = sectionStr + res;
    n /= 10000;
    bigUnitIdx++;
  }

  // 清理边缘空格和重复的零（简化处理）
  if (res.back() == u'零')
    res.pop_back();
  return res;
}
int main() {}