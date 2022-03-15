/*
 * @Author: proanimer
 * @Date: 2022-03-15 08:21:04
 * @LastEditTime: 2022-03-15 08:43:44
 * @LastEditors: proanimer
 * @Description: 
 */

#include<iostream>
#include<vector>
using namespace std;

int main()
{class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int length = matrix.size();
        for (int i = 0; i < length/2; i++)
        {
            for (int j = i; j < length-i-1; j++)
            {
                    int temp = matrix[i][j];
                    int m = length - j -1;
                    int n = length - i -1;
                    matrix[i][j] = matrix[m][i];
                    matrix[m][i] = matrix[n][m];
                    matrix[n][m] = matrix[j][n];
                    matrix[j][n] = temp;
            }
            

        }
        
    }
};

}