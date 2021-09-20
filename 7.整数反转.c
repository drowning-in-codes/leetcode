/*
 * @lc app=leetcode.cn id=7 lang=c
 *
 * [7] 整数反转
 */

// @lc code=start
#include<limits.h>

int reverse(int x){
    int temp;
    int sum=0;
    while(x)
    {
        temp = x%10;
        if(sum>INT_MAX/10||(sum==INT_MAX/10&&temp>7))
        return 0;
        if(sum<INT_MIN/10||(sum==INT_MIN&&temp<-8))
        return 0;
        sum = sum*10+temp;
        x /= 10;
    }
    return sum;

}
// @lc code=end

