/*
 * @Author: proaniemr
 * @Date: 2022-03-14 22:16:46
 * @LastEditors: proaniemr
 * @LastEditTime: 2022-03-14 22:39:15
 * @Description:
 */

#include <iostream>
#include <vector>

using namespace std;
int main()
{
    class Solution
    {
    public:
        bool isValidSudoku(vector<vector<char> > &board)
        {
            vector<vector<int> >row(board.size(),vector<int>(board.size(),0));
            vector<vector<int> >col(board.size(),vector<int>(board.size(),0));
            vector<vector<int> >cell(board.size(),vector<int>(board.size(),0));
            for (int i = 0; i < board.size(); i++)
            {
                for (int j = 0; j < board.size(); j++)
                {
                    int k = i/3*3+j/3;
                    if(board[i][j] == '.')
                        continue;
                    int num = board[i][j] - '0' - 1 ;
                    if(row[i][num] == 1 || col[j][num] || cell[k][num] == 1)
                    {
                        return false;
                    }
                    row[i][num] = col[j][num] = cell[k][num] = 1;
                }
                
            }
            return true;
            
        }
    };
}
