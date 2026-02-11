#include <iostream>
#include <stdexcept>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char16_t, int> segments = {
    {u'亿', 1e8},
    {u'万', 10000},
};
unordered_map<char16_t, int> units = {
    {u'千', 1000},
    {u'百', 100},
    {u'十', 10},
};
unordered_map<char16_t, int> vals = {
    {u'零', 0}, {u'一', 1}, {u'二', 2}, {u'三', 3}, {u'四', 4},
    {u'五', 5}, {u'六', 6}, {u'七', 7}, {u'八', 8}, {u'九', 9},

};
class Solution {
public:
  int chineseNumsToArabicNums(u16string s) {
    int res{};
    int segs{}; // 段内值
    int val{};  // 每个值
    // 1012
    for (auto &ch : s) {
      // 按照万/亿来分段
      if (units.count(ch)) {
        // 如果是单位
        // 避免类似一千零十二这种情况
        if (val == 0 && units[ch] == 10) {
          val = 1;
        }
        segs += val * units[ch];
        val = 0;
      } else if (vals.count(ch)) {
        val = vals[ch];
      } else if (segments.count(ch)) {
        // 一段
        // xxx 万
        segs += val;
        res += segs * segments[ch];
        segs = 0;
        val = 0;
      } else {
        throw invalid_argument("错误参数");
      }
    }
    // 剩下的值
    if (val) {
      res += val;
    }
    if (segs) {
      res += segs;
    }
    return res;
  }
};
// 十万九千零二十->109020

// 保证在INT_MAX之内
// 三千三百三十三 万
// 四个一组
// 万

long long cnToAr(std::u16string s) {
  std::unordered_map<char16_t, int> digits = {
      {u'零', 0}, {u'一', 1}, {u'二', 2}, {u'三', 3}, {u'四', 4},
      {u'五', 5}, {u'六', 6}, {u'七', 7}, {u'八', 8}, {u'九', 9}};
  std::unordered_map<char16_t, long long> units = {{u'十', 10},
                                                   {u'百', 100},
                                                   {u'千', 1000},
                                                   {u'万', 10000},
                                                   {u'亿', 100000000}};

  long long total = 0;   // 总结果
  long long section = 0; // 当前“万”或“亿”之内的累加和
  long long num = 0;     // 暂存当前读到的数字

  for (char16_t ch : s) {
    if (digits.count(ch)) {
      num = digits[ch];
    } else if (units.count(ch)) {
      long long unit = units[ch];
      if (unit == 10000 || unit == 100000000) {
        // 遇到大单位，结算当前 section 并乘以权重
        section = (section + num) * unit;
        // 如果是一亿,表示最大的节结束，累加到total结果上并清空section
        // 如果是一万，可能后序还有更大的节，不管
        if (unit == 1e8) {
          total += section;
          section = 0;
        }
      } else {
        // 遇到小单位（十百千）
        if (num == 0 && unit == 10)
          num = 1; // 处理“十二”开头的“十”
        section += num * unit;
      }
      num = 0;
    }
  }
  return total + section + num;
}
int main() {
  Solution sol;
  cout << sol.chineseNumsToArabicNums(u"一千零十二");
  cout << cnToAr(u"一万亿");
}