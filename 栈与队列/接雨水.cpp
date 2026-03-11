#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  int trap(vector<int> &height) {
    int n = height.size();
    stack<int> st;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
      while (!st.empty() && height[i] > height[st.top()]) {
        int mid = st.top();
        st.pop();
        if (st.empty())
          break;
        int left = st.top();
        int h = min(height[left], height[i]) - height[mid];
        int w = i - left - 1;
        ans += h * w;
      }
      st.push(i);
    }
    return ans;
  }
};
