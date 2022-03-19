#include <string>
#include <vector>
#include<iostream>
using namespace std;
int main()
{
class Solution
{
public:
    int firstUniqChar(string s)
    {
        int length = s.size();
        bool flag = true;
        // cout<<length;
        vector<int> v(length, 0);
        for (int i = 0; i < length; i++)
        {
            
            for (int j = 0; j < length; j++)
            {
                if (i != j && s[i] == s[j] && (!v[i]) && (!v[j]))
                {
                    
                    v[i] = v[j] = 1;
                    flag = false;
                    break;
                }
            }
            if (flag && !v[i])
            {
                return i;
            }
            flag = true;
        }
        return -1;
    }
};
    Solution s = Solution();
    cout<<s.firstUniqChar("aabb");
}