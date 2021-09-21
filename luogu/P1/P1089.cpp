/**
 * @file P1089.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-09-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <iostream>

using namespace std;

int main(void)
{
    int save_money = 0;
    int money = 0;
    int total = 0;
    int flag = 1;
    for (int i = 0; i < 12; i++)
    {
        scanf("%d", &money);
        total += 300;
        total -= money;
        if (total < 0)
        {
            printf("-%d\n", (i + 1));
            flag = 0;
            break;
        }
        else
        {

            save_money += (total / 100) * 100;
            total %= 100;
        }
    }

    if (flag)
    {
        //! printf(" %d\n", (save_money * 1.2 + total));
        //*這裏我一直沒看到,int乘了一個浮點數最後又是%d
        //*所以輸出是0
        cout << save_money * 1.2 + total << endl;
    }
    return 0;
}