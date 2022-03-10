#include<iostream>
#include<vector>

using namespace std;

int main(){
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //双指针解决
        if(nums.size() == 0)
            return 0;
        int left = 0;
        for(int right = 1;right<nums.size();right++)
        {
            if(nums[left]!=nums[right])
            {
                nums[++left] = nums[right];
            }
        }
        return ++left;
    }
};

Solution s;
vector<int>v;
// v.push_back(1);
// v.push_back(1);
// v.push_back(2);
v[0] = 1 ;
v[1] = 1;
v[2] = 2;
cout<<v.size();
}