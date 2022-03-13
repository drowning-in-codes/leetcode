// ; 给你两个整数数组 nums1 和 nums2 ，请你以数组形式返回两数组的交集。
// ; 返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致
// ; （如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    

}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *num1, const void *num2)
{
    return *(int *)num1 - *(int *)num2;
}

int *intersect(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);
    int *point1 = nums1;
    int *point2 = nums2;
    int i = 0, j = 0;
    int *result = (int *)malloc(sizeof(int) * (nums1Size + nums2Size));
    int count = 0;
    while (i < nums1Size && j < nums2Size)
    {
        //小于
        if (*(point1 + i) < *(point2 + j))
        {
            i++;
        }
        //大于
        else if (*(point1 + i) > *(point2 + j))
        {
            j++;
        }
        else
        {
            result[count] = *(point1 + i);
            i++;
            j++;
            count++;
        }
    }

    result = (int *)realloc(result, count * sizeof(int));
    *returnSize = count;
    return result;
}