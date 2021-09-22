#include<stdio.h>
#include<iostream>
using namespace std;

int main(void)
{
    int scho_t,mom_t;
    int flag = 0;
    int all_t=0;
    for(int i=0;i<7;i++)
    {
        scanf("%d %d",&scho_t,&mom_t);
        if(scho_t+mom_t>8)
        {
            if(all_t<scho_t+mom_t)
            {
                all_t = scho_t+mom_t;
                flag = i+1;
            }       
        }

    }
    if(flag)
    printf("%d\n",flag);
    else
    printf("0\n");
    return 0;

}