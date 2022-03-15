/*
 * @Author: proanimer
 * @Date: 2022-03-15 11:15:20
 * @LastEditTime: 2022-03-15 11:15:20
 * @LastEditors: proanimer
 * @Description: 
 */
#include<iostream>
using namespace std;
int main()
{
    class Solution {
    public:
    int reverse(int x) {
         int res = 0;
        while (x != 0) {
            int t = x % 10;
            int newRes = res * 10 + t;
            //如果数字溢出，直接返回0
            cout<<newRes<<" "<<res<<endl;
            if ((newRes - t) / 10 != res)
                return 0;
            res = newRes;
            x = x / 10;
        }
        return res;
    }
    Solution()
    {

    }
};

    Solution mysolution =  Solution();
   int r =  mysolution.reverse(1534236469);
    cout<<r;
}

