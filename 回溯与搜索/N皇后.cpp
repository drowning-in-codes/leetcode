#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<int> col(n, 0), d1(2 * n, 0), d2(2 * n, 0);
    vector<string> board(n, string(n, '.'));
    dfs(0, n, col, d1, d2, board, res);
    return res;
  }

private:
  void dfs(int r, int n, vector<int> &col, vector<int> &d1, vector<int> &d2,
           vector<string> &board, vector<vector<string>> &res) {
    if (r == n) {
      res.push_back(board);
      return;
    }
    for (int c = 0; c < n; ++c) {
      if (col[c] || d1[r - c + n] || d2[r + c])
        continue;
      col[c] = d1[r - c + n] = d2[r + c] = 1;
      board[r][c] = 'Q';
      dfs(r + 1, n, col, d1, d2, board, res);
      board[r][c] = '.';
      col[c] = d1[r - c + n] = d2[r + c] = 0;
    }
  }
};
