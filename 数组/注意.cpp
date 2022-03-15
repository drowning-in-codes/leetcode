/*
 * @Author: proanimer
 * @Date: 2022-03-14 10:40:32
 * @LastEditTime: 2022-03-14 22:32:45
 * @LastEditors: proaniemr
 * @Description: 使用cpp的注意项
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <queue>
#include<stack>
using namespace std;

int main()
{
    vector<int> nums;

    int n = 21;

    vector<int> nums(n); //初始化数组 大小为n,值均为0

    vector<int> nums(n, 2); // 大小为n 值为2

    vector<int> nums{1, 3, 5};

    vector<vector<int>> dp; //二维数组

    int m = 12;
    vector<vector<bool> > dp(m, vector<bool>(n, true));

    //成员函数
    nums.empty(); //判断
    nums.size();
    nums.back(); //返回对最后一个数的引用
    nums.push_back(10);
    nums.pop_back();

    string s; // s是一个空字符串

    string s = "abc";
    s.size();
    s.empty();
    s.push_back('c');
    s.pop_back();
    s.substr(0, 5);

    s += "fuck";

    unordered_map<string, vector<int>> mapping;
    mapping.size();
    mapping.empty();
    mapping.count();
    vector<int> arr(5, 2);
    mapping.emplace("fuck", arr);
    // mapping.cout();
    // mapping.erase();
    // for(auto it : mapping){
    // cout << typeid(it).name();
    unordered_set<int> visited;
    visited.size();
    visited.empty();
    // visited.insert();
    // visited.erase();
    //队列
    queue<int> q;
    queue<string> q;
    q.empty();
    q.size();
    q.push();
    q.front();
    q.pop();

    stack<int> stk;
    stack<int> stk2;
    


}
