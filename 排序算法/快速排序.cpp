#include <vector>
using namespace std;

class Solution {
public:
  enum PartitionType { LOMUTO = 0, HOARE = 1, THREE_WAY = 2 };

  vector<int> sortArray(vector<int> &nums) {
    // 默认使用 Hoare 分区
    quickSortHoare(nums, 0, (int)nums.size() - 1);
    return nums;
  }

  // 便于练习时切换不同分区方式
  vector<int> sortArrayByPartition(vector<int> nums, PartitionType type) {
    if (nums.empty())
      return nums;
    if (type == LOMUTO) {
      quickSortLomuto(nums, 0, (int)nums.size() - 1);
    } else if (type == HOARE) {
      quickSortHoare(nums, 0, (int)nums.size() - 1);
    } else {
      quickSortThreeWay(nums, 0, (int)nums.size() - 1);
    }
    return nums;
  }

private:
  // 分区差异速记：
  // 1) Lomuto: pivot 常取末尾，返回 pivot 的最终下标 p（pivot 已就位）
  //    递归区间是 [l, p-1] 与 [p+1, r]
  // 2) Hoare: pivot 可取中间值，返回分界下标 p（不是 pivot 最终下标）
  //    只保证 [l, p] <= pivot, [p+1, r] >= pivot
  //    递归区间必须是 [l, p] 与 [p+1, r]，不能写成 p-1 / p+1
  // 3) 三路分区: 一次划分出 < pivot / == pivot / > pivot 三段
  //    对重复元素多的数组更友好
  void swapInt(int &x, int &y) {
    int t = x;
    x = y;
    y = t;
  }

  // Lomuto 返回值语义：返回 pivot 的最终位置 p（a[p] 已固定）
  int partitionLomuto(vector<int> &a, int l, int r) {
    int pivot = a[r];
    int i = l;
    for (int j = l; j < r; ++j) {
      if (a[j] <= pivot) {
        swapInt(a[i], a[j]);
        ++i;
      }
    }
    swapInt(a[i], a[r]);
    return i;
  }

  void quickSortLomuto(vector<int> &a, int l, int r) {
    if (l >= r)
      return;
    int p = partitionLomuto(a, l, r);
    // 因为 p 是 pivot 最终位置，所以两侧递归跳过 p
    quickSortLomuto(a, l, p - 1);
    quickSortLomuto(a, p + 1, r);
  }

  // Hoare 返回值语义：返回分界点 p（不保证某个 pivot 元素就位）
  int partitionHoare(vector<int> &a, int l, int r) {
    int pivot = a[l + (r - l) / 2];
    int i = l - 1, j = r + 1;
    while (true) {
      do {
        ++i;
      } while (a[i] < pivot);
      do {
        --j;
      } while (a[j] > pivot);
      if (i >= j)
        return j;
      swapInt(a[i], a[j]);
    }
  }

  void quickSortHoare(vector<int> &a, int l, int r) {
    if (l >= r)
      return;
    int p = partitionHoare(a, l, r);
    // Hoare 的 p 是“边界”而不是“pivot 最终下标”，左区间应包含 p
    quickSortHoare(a, l, p);
    quickSortHoare(a, p + 1, r);
  }

  // 三路分区：把等于 pivot 的元素集中在中间，重复值较多时更高效
  void quickSortThreeWay(vector<int> &a, int l, int r) {
    if (l >= r)
      return;
    int pivot = a[l];
    int lt = l, i = l + 1, gt = r;
    while (i <= gt) {
      if (a[i] < pivot) {
        swapInt(a[lt], a[i]);
        ++lt;
        ++i;
      } else if (a[i] > pivot) {
        swapInt(a[i], a[gt]);
        --gt;
      } else {
        ++i;
      }
    }
    quickSortThreeWay(a, l, lt - 1);
    quickSortThreeWay(a, gt + 1, r);
  }
};
