#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minp = 1e9, ans = 0;
        for (int p : prices) {
            if (p < minp) minp = p;
            if (p - minp > ans) ans = p - minp;
        }
        return ans;
    }
};
