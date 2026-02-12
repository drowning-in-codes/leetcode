using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int v = x ^ y;
        int cnt = 0;
        while (v) { v &= (v - 1); cnt++; }
        return cnt;
    }
};
