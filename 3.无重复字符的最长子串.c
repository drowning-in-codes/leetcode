/*
 * @lc app=leetcode.cn id=3 lang=c
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start

#include<string.h>
int lengthOfLongestSubstring(char * s){
    int res = 0;
    int len = strlen(s);
    int freq[256] = {0};
    int l = 0,r = -1;
    while(l<len)
    {
        if(r<len-1&&freq[s[r+1]]==0)
        {
            freq[s[++r]]++;
        }
        else
        {
            freq[s[l++]]--;
        }
         res = fmax(res,r-l+1);
    }
   
    return res;
}
// @lc code=end

