/*
给定一个数组 prices ，其中 prices[i] 表示股票第 i 天的价格。

在每一天，你可能会决定购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以购买它，然后在 同一天 出售。
返回 你能获得的 最大 利润 。
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
