#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    int n = heights.size();
    stack<int> st;
    int ans = 0;

    for (int i = 0; i <= n; ++i) {
      int h = (i == n ? 0 : heights[i]);
      while (!st.empty() && heights[st.top()] > h) {
        int height = heights[st.top()];
        st.pop();
        int left = st.empty() ? -1 : st.top();
        int width = i - left - 1;
        ans = max(ans, height * width);
      }
      st.push(i);
    }
    return ans;
  }
};
