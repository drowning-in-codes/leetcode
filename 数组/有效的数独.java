/*
 * @Author: proaniemr
 * @Date: 2022-03-13 22:02:23
 * @LastEditors: proaniemr
 * @LastEditTime: 2022-03-13 23:15:27
 * @Description: 请填写简介
 */
import java.util.ArrayList;
import java.util.LinkedList;

class 有效的数独 {
    
    public static void main(String[] args) {
       
    }

    public boolean isValidSudoku(char[][] board) {
      int length = board.length;
      int row[][] = new int[length][length];
      int col[][] = new int[length][length];
      int cell[][] = new int[length][length];
      for (int i = 0; i < cell.length; i++) {
          for (int j = 0; j < cell.length; j++) {
              System.out.println(row[i][j]);
          }
      }
      for (int i = 0; i < length; i++) {
          for (int j = 0; j < length; j++) {
              if(board[i][j] == '.')
                continue;
              int num = board[i][j] - '0' -1;
              int cellnum = i+j/3;
              if(row[i][num]!=0 || col[j][num] !=0|| cell[cellnum][num] !=0)
              {
                  return false;
              }
              row[i][num] = col[j][num] = cell[cellnum][num] = 1;
          }
      }
        return true;
        }
        public boolean isValidSudoku2(char board[][]) {
            int length = board.length;
            //二维数组line表示的是对应的行中是否有对应的数字，比如line[0][3]
            //表示的是第0行（实际上是第1行，因为数组的下标是从0开始的）是否有数字3
            int line[][] = new int[length][length];
            int column[][] = new int[length][length];
            int cell[][] = new int[length][length];
            for (int i = 0; i < length; ++i)
                for (int j = 0; j < length; ++j) {
                    //如果还没有填数字，直接跳过
                    if (board[i][j] == '.')
                        continue;
                    //num是当前格子的数字
                    int num = board[i][j] - '0' - 1;
                    //k是第几个单元格，9宫格数独横着和竖着都是3个单元格
                    int k = i / 3 * 3 + j / 3;
                    //如果当前数字对应的行和列以及单元格，只要一个由数字，说明冲突了，直接返回false。
                    //举个例子，如果line[i][num]不等于0，说明第i（i从0开始）行有num这个数字。
                    if (line[i][num] != 0 || column[j][num] != 0 || cell[k][num] != 0)
                        return false;
                    //表示第i行有num这个数字，第j列有num这个数字，对应的单元格内也有num这个数字
                    line[i][num] = column[j][num] = cell[k][num] = 1;
                }
            return true;
        }
    
  
    }
    
