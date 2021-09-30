/**
 * @file P1980.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-09-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <iostream>

using namespace std;

int config(int, int);

int main(void)
{
    int n, x;
    int t = 0;
    scanf("%d %d", &n, &x);
    for (int i = 1; i <= n; i++)
    {
        t += config(x, i);
    }
    cout << t << endl;
    return 0;
}

int config(int n, int num)
{
    int digit;
    int times = 0;
    while (num)
    {
        digit = num % 10;
        if (digit == n)
            times += 1;
        num /= 10;
    }
    return times;
}
