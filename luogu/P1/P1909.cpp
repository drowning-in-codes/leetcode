/**
 * @file P1909.cpp
 * @author your name (you@domain.com)
 * @brief
 *P老师需要去商店买n支铅笔作为小朋友们参加NOIP的礼物。她发现商店一共有 33种包装的铅笔，不同包装内的铅笔数量有可能不同，价格也有可能不同。为了公平起 见，P老师决定只买同一种包装的铅笔。
 *    商店不允许将铅笔的包装拆开，因此P老师可能需要购买超过nn支铅笔才够给小朋 友们发礼物。
 *   现在P老师想知道，在商店每种包装的数量都足够的情况下，要买够至少nn支铅笔最少需要花费多少钱  
 * @version 0.1
 * @date 2021-09-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <iostream>

using namespace std;

int main(void)
{
    int n; //鉛筆屬靈
    scanf("%d", &n);
    int num, price;
    int min = INT32_MAX;
    int a_price;
    int s, r;
    for (int i = 1; i < 4; i++)
    {
        scanf("%d %d", &num, &price);
        s = n / num;
        r = n % num;
        if (r)
            s += 1;
        a_price = s * price;
        if (a_price < min)
            min = a_price;
    }
    cout<<min<<endl;
    return 0;
}
