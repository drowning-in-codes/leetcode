using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long long l = 0, r = x;
        while (l <= r) {
            long long m = l + (r - l) / 2;
            long long sq = m * m;
            if (sq == x) return (int)m;
            if (sq < x) l = m + 1; else r = m - 1;
        }
        return (int)r;
    }
};
