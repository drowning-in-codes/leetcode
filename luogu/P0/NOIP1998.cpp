/**
 * @file NOIP1998.cpp
 * @author your name (you@domain.com)
 * @brief 将 1, 2, \ldots , 91,2,…,9 共 99 个数分成 33 组，
 * 分别组成 33 个三位数，且使这 33 个三位数构成 1 : 2 : 31:2:3 的比例，
 * 试求出所有满足条件的 33 个三位数。
 * @version 0.1
 * @date 2021-09-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;
int arr[10];
void generate();
int main(void)
{
    generate();
}
void generate()
{

    for (int i = 123; i <= 329; i++)
    {
        int flag = 1;
        memset(arr, 0, sizeof(arr));
        int x = i;
        int y = x * 2;
        int z = x * 3;
        int j = y, k = z;
        while (j)
        {
            arr[j % 10]++;
            j /= 10;
        }
        while (x)
        {
            arr[x % 10]++;
            x /= 10;
        }
        while (k)
        {
            arr[k % 10]++;
            k /= 10;
        }
        for (int t = 1; t < 10; t++)
        {
            if (arr[t] != 1)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            printf("%d %d %d\n", i, y, z);
    }
    
}