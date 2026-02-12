#include <vector>
using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    quickSort(nums, 0, (int)nums.size() - 1);
    return nums;
  }

private:
  void quickSort(vector<int> &a, int l, int r) {
    if (l >= r)
      return;
    int i = l, j = r, pivot = a[l + (r - l) / 2];
    while (i <= j) {
      while (a[i] < pivot)
        ++i;
      while (a[j] > pivot)
        --j;
      if (i <= j) {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
        ++i;
        --j;
      }
    }
    if (l < j)
      quickSort(a, l, j);
    if (i < r)
      quickSort(a, i, r);
  }
};
