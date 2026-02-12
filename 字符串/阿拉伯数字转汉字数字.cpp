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

std::vector<u16string> digits = {u"零", u"一", u"二", u"三", u"四",
                                 u"五", u"六", u"七", u"八", u"九"};
std::vector<u16string> units = {u"", u"十", u"百", u"千"};
std::vector<u16string> bigUnits = {u"", u"万", u"亿"};
wstring_convert<codecvt_utf8_utf16<char16_t>, char16_t> convert;
void outputu16string16(const u16string &str) {
  // 转换为普通的 std::string
  string utf8_str = convert.to_bytes(str);
  cout << utf8_str;
}
// 将[0,10000)段内的值
u16string sectionToChinese(int num) {
  u16string sectionStr;
  bool hasZero{};
  for (int i = 0; i < 4; i++) {
    int n = num % 10;
    // 当前位是0
    if (n == 0) {
      // 如果之前有内容,比如1001,记录
      // 如果之前没有内容，也就是刚开始或者之前也是零，比如1100，110. 不加零
      if (!sectionStr.empty()) {
        hasZero = true;
      }
    } else {
      // 非零
      // 之前有零
      if (hasZero) {
        // 添加零
        sectionStr = digits[0] + sectionStr;
        hasZero = false;
      }
      // 处理当前非零部分
      sectionStr = digits[n] + units[i] + sectionStr;
    }
    num = num / 10;
  }

  return sectionStr;
}
u16string arToCn2(long long n) {
  if (n == 0)
    return u"零";

  std::u16string res = u"";
  int bigUnitIdx = 0;
  bool needExtraZero = false; // 用于处理段间补零
  while (n > 0) {
    int section = n % 10000;
    if (section == 0) {
      // 当前整个段为0，记录
      // 如果当前 part 为 0 但后面还有数字，补零逻辑
      if (!res.empty()) {
        needExtraZero = true;
      }
    } else {
      u16string sectionStr = sectionToChinese(section);
      // 间隔0
      if (needExtraZero) {
        res = digits[0] + res;
        needExtraZero = false;
      }
      // 加上大单位（万/亿）
      res = sectionStr + bigUnits[bigUnitIdx] + res;
    }
    // 如果这一段不足 1000（即千位是0），且后面已经有高位结果了，需要补零
    if (section > 0 && section < 1000 && n > 0) {
      needExtraZero = true;
    }
    n /= 10000;
    bigUnitIdx++;
  }
  return res;
}

int main() {
  setlocale(LC_ALL, ".utf-8");
  auto s = arToCn2(9091000);
  outputu16string16(s);
  return 0;
}