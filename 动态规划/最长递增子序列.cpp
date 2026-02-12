#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tail;
        for (int v : nums) {
            auto it = lower_bound(tail.begin(), tail.end(), v);
            if (it == tail.end()) tail.push_back(v);
            else *it = v;
        }
        return (int)tail.size();
    }
};
