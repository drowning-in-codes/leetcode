/**
 * @file P1014.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-09-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <cstdio>
#include <iostream>

using namespace std;

int main(void)
{
    //*每一行有固定的个数
    int num=0;
    int n;
    scanf("%d", &n);
    int i;
    for (i = 1;; i++)
    {
        num+=i;
        //* i为行数
        if(num>=n)
        {
            break;
        }
    }
    //?说明是第i行  但不知道从哪个方向开始
    //*若为奇数 从下往上,分子递减 分母递增
    int t = num-n;
    if(i%2==1)
    {
        cout<< 1+t<<"/"<<i-t<<endl; 
    }
    //*若为偶数,从上往下,分子递增 分母递减
    else
    {
        cout<< i-t<<"/"<<t+1<<endl; 
    }
    
}
