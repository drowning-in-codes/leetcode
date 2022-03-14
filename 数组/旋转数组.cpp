

#include<stdio.h>
#include<stdlib.h>
void rotate(int* nums, int numsSize, int k);
int main()
{
    int arr[] = {1,24,5,6};
    rotate(arr,4,2);
    for(int i=0;i<4;i++)
    {
        printf("%d",arr[i]);
    }
    return 0;

}

void rotate1(int* nums, int numsSize, int k){
    //使用临时数组

    int *temp = (int*)malloc(numsSize*sizeof(int));
    for(int i=0;i<numsSize;i++)
    {
        *(temp+i) = *(nums+i);
    }
    for(int i = 0;i<numsSize;i++)
    {
        *(nums+(k+i)%numsSize) = *(temp+i);
    }
}

void rotate2(int* nums, int numsSize, int k){
    //多次反转
    //先整个反转 再反转前k个 再反转后几个
    k %= numsSize;
    reverse(nums,0,numsSize-1);
    reverse(nums,0,k-1);
    reverse(nums,k,numsSize-1);

}

void reverse(int *nums,int start,int end)
{
    while (start<end)
    {
        int temp;
        temp = nums[start];
        nums[start++] = nums[end];
        nums[end--] = temp;
    }
    

}