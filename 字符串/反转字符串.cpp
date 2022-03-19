/*
 * @Author: proanimer
 * @Date: 2022-03-15 10:15:36
 * @LastEditTime: 2022-03-15 11:07:24
 * @LastEditors: proanimer
 * @Description:
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    class Solution
    {
    public:
        void reverseString(vector<char> &s)
        {
            int size = s.size();
            for(int i=0;i<size/2;i++)
            {
                char temp = s[i];
                s[i] = s[size-1-i];
                s[size-1-i] = temp;
            }
            return ;
        }
    };
}