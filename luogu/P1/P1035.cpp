/**
 * @file P1035.cpp
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

int main(void)
{
    int k;
    scanf("%d", &k);
    double Sn = 0;
    int n;
    double i;
    for (i = 1; ; i++)
    {
        Sn += 1 / i;
        if (Sn > k)
            break;
    }
    cout << i << endl;
    return 0;
}
