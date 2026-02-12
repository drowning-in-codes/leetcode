// 11234 -> 一万一千二百三十四 假设小于INT_MAX
// 10024 ->一万零二十四
#include <codecvt>
#include <iostream>
#include <locale>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;
// 1100,0112

std::u16string arToCn2(long long n) {
  if (n == 0)
    return u"零";

  std::vector<char16_t> digits = {u'零', u'一', u'二', u'三', u'四',
                                  u'五', u'六', u'七', u'八', u'九'};
  std::vector<char16_t> units = {u' ', u'十', u'百', u'千'};
  std::vector<char16_t> bigUnits = {u' ', u'万', u'亿'};

  std::u16string res = u"";
  int bigUnitIdx = 0;
  bool lastSectionZero = false;
  while (n > 0) {
    int section = n % 10000;
    std::u16string sectionStr = u"";
    if (section == 0) {
      // 整组为零
      if (!res.empty())
        lastSectionZero = true;
    } else {
      int tempPart = section;
      bool innerZero = false; // 组内连续零标志
      // 补零逻辑：如果当前组不足千位，且右侧（低位）已经有数字，需要补零
      // 例如 1,0001 中的 "0001" 处理完是 "一"，需要补零变成 "零一"
      if (lastSectionZero || (section < 1000 && !res.empty())) {
        res = digits[0] + res;
        lastSectionZero = false;
      }
      for (int i = 0; i < 4; ++i) {
        int d = tempPart % 10;
        if (d == 0) {
          if (!sectionStr.empty()) {
            innerZero = true;
          }
        } else {
          if (innerZero) {
            sectionStr = u"零" + sectionStr;
            innerZero = false;
          }
          std::u16string temp = u"";
          temp += digits[d];
          if (i > 0)
            temp += units[i];
          sectionStr = temp + sectionStr;
        }
        tempPart /= 10;
      }
      // 加上大单位（万/亿）
      if (bigUnitIdx > 0 && !sectionStr.empty()) {
        sectionStr += bigUnits[bigUnitIdx];
      }
      res = sectionStr + res;
    }
    n /= 10000;
    bigUnitIdx++;
  }

  return res;
}
int main() {
  setlocale(LC_ALL, ".utf-8");
#ifdef WINDOWS
  SetOutput
#endif
      auto s = arToCn2(10011);
  // 定义从 UTF-16 到 UTF-8 的转换器
  wstring_convert<codecvt_utf8_utf16<char16_t>, char16_t> convert;
  // 转换为普通的 std::string
  string utf8_str = convert.to_bytes(s);
  cout << utf8_str;
  return 0;
}