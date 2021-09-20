/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        // 经过测试,有些题会超时
    //     vector<int>::iterator it;
    //     vector<int>:: iterator it_2;
    //     int low;
    //     int length;
    //     int area;
    //     int max_area=0;
    //     for(it=height.begin();it<height.end();it++)  
    //     {
    //         for(it_2 = it+1;it_2<height.end();it_2++)
    //         {
    //        //求出较小高度
    //         if(*it<*it_2)
    //         {
    //             low = *it;
    //         }
    //         else
    //             low = *it_2;
           
    //         length = it_2-it;
           
    //         area = length*low;//求出面积
           
    //         if(max_area<area)
    //             max_area = area;//保留最大面积
    //         }
    //     }
        
    // return max_area;
    //关于这个题的做法
    //我是打算两个for循环嵌套,但这确实是有点莽的
//    int length;
//    int low;
//    int area;
//    int max_area = 0;
//     for(int i = 0;i<height.size();i++)
//     {
//         for(int j=i+1;j<height.size();j++)
//         {
//           low = (height[i]<height[j])?height[i]:height[j];
//           length = j-i;
//           area = length*low;
//           max_area = (max_area<area)?area:max_area;
//         }
//     }

//     return max_area;
/*
        看了题解知道大概怎么做了
        设两个头尾指针(不一定非要用指针)
        这时候宽最大,要是面积更大,则必须使高更大,只要使高较小的那一边变大就行了(木桶效应)
*/
    int low = 0;
    int high = height.size()-1;
    int ans=0;
    int area;
    int l;
    while(low<high)
    {
        l = min(height[low],height[high]);//这里有min函数.c++的东西,只用c的表示很难受
        area = (high-low)*l;
        ans = max(area,ans);
        if(l==height[low])
        low++;
        else
        high--;
    }
return ans;
    }
};
// @lc code=end

