#include <vector>
using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    vector<int> tmp(nums.size());
    mergeSort(nums, tmp, 0, (int)nums.size() - 1);
    return nums;
  }

private:
  void mergeSort(vector<int> &a, vector<int> &tmp, int l, int r) {
    if (l >= r)
      return;
    int m = l + (r - l) / 2;
    mergeSort(a, tmp, l, m);
    mergeSort(a, tmp, m + 1, r);
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r)
      tmp[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];
    while (i <= m)
      tmp[k++] = a[i++];
    while (j <= r)
      tmp[k++] = a[j++];
    for (int x = l; x <= r; ++x)
      a[x] = tmp[x];
  }
};
