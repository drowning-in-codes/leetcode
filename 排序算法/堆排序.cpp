#include <vector>
using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    int n = nums.size();
    for (int i = n / 2 - 1; i >= 0; --i)
      heapify(nums, n, i);
    for (int i = n - 1; i > 0; --i) {
      int t = nums[0];
      nums[0] = nums[i];
      nums[i] = t;
      heapify(nums, i, 0);
    }
    return nums;
  }

private:
  void heapify(vector<int> &a, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] > a[largest])
      largest = l;
    if (r < n && a[r] > a[largest])
      largest = r;
    if (largest != i) {
      int t = a[i];
      a[i] = a[largest];
      a[largest] = t;
      heapify(a, n, largest);
    }
  }
};
