/**
 * @file P1037.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-09-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<cstdio>
#include<iostream>

using namespace std;

int main(void)
{
    int n;
    scanf("%d",&n);
    int reverse_num=0;
    int t;
    while (n)
    {
        t = n%10;
        reverse_num+=t;
        if((n/=10)!=0)
        reverse_num*=10;
    }
    cout<<reverse_num<<endl;
    return 0;
    

    
}