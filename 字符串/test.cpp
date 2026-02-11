#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
  // 使用 static 成员，避免重复创建 map
  inline static const unordered_map<char16_t, long long> vals = {
      {u'零', 0}, {u'一', 1}, {u'二', 2}, {u'三', 3}, {u'四', 4},
      {u'五', 5}, {u'六', 6}, {u'七', 7}, {u'八', 8}, {u'九', 9} // 修正了“九”
  };
  inline static const unordered_map<char16_t, long long> units = {
      {u'十', 10}, {u'百', 100}, {u'千', 1000}};
  inline static const unordered_map<char16_t, long long> segments = {
      {u'万', 10000}, {u'亿', 100000000}};

public:
  long long chineseNumsToArabicNums(u16string s) {
    long long res = 0;     // 最终结果
    long long section = 0; // “万”或“亿”之内的段内和
    long long val = 0;     // 当前数字

    for (char16_t ch : s) {
      if (vals.count(ch)) {
        val = vals.at(ch);
      } else if (units.count(ch)) {
        long long unit = units.at(ch);
        if (val == 0 && unit == 10)
          val = 1; // 处理“十二”
        section += val * unit;
        val = 0;
      } else if (segments.count(ch)) {
        long long segUnit = segments.at(ch);
        // 核心修正：section 加上当前的 val，再乘以万或亿
        section = (section + val) * segUnit;

        // 处理“亿”和“万”的嵌套（如一亿万，虽然少见但逻辑要通）
        if (segUnit == 100000000) {
          res += section;
          section = 0;
        } else {
          // 如果是万，先存在 section 里，可能后面还有亿
        }
        val = 0;
      } else {
        // 处理零，通常不需要操作，只需重置 val 为 0 即可
        val = 0;
      }
    }
    return res + section + val;
  }
};
int main() {
  Solution sol;
  cout << sol.chineseNumsToArabicNums(u"一万二千");
}