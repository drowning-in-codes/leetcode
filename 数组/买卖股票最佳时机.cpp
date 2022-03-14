/*** 
 * @Author: proanimer
 * @Date: 2022-03-14 00:30:05
 * @LastEditTime: 2022-03-14 08:59:52
 * @LastEditors: proanimer
 * @Description: 
 * @FilePath: \leetcode\数组\买卖股票最佳时机.cpp
 * @
 */

#include<iostream>
#include<vector>
using namespace std;

int main()
{
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        if(prices.size()<=1)
        {
            return 0;
        }
        for(int i = 0;i<prices.size()-1;i++)
        {
            if(prices[i+1]>prices[i])
            {
                max+=prices[i+1] - prices[i];
            }
        }
        return max;
    }
};

}
