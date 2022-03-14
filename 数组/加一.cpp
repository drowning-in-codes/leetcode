/*
给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>

using namespace std;
int *plusOne(int *digits, int digitsSize, int *returnSize);
int main(void)
{
    int digit[] = {0};
    int size = 0;
    int *_ = plusOne(digit, 1, &size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", _[i]);
    }
    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *plusOne(int *digits, int digitsSize, int *returnSize)
{
    *returnSize = digitsSize;
    int overflow = false;
    for (int i = digitsSize - 1; i >= 0; i--)
    {
        if (++digits[i] >= 10)
        {
            digits[i] = 0;
            if (i == 0)
            {
                overflow = true;
                (*returnSize)++;
            }
        }
        else
        {
            break;
        }
    }
    int *result = (int *)malloc((*returnSize) * sizeof(int));
    int j;
    for (int i = 0, j = i; i < (*returnSize) ; i++, j++)
    {

        if (overflow)
        {
            result[0] = 1;
            j--;
            overflow = false;
        }
        else
        {
            result[i] = digits[j];
        }
    }

    return result;
}