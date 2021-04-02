// 37. 解数独
// 编写一个程序，通过填充空格来解决数独问题
//

#include <vector>

using std::vector;

class Solution {
    bool isValid(vector<vector<char>>& board, int row, int col, char n) {
        for (int i = 0; i < 9; ++i)
            if (board[row][i] == n || board[i][col] == n ||
                board[(row/3)*3 + i/3][(col/3)*3 + i%3] == n)
                return false;

        return true;
    }

    bool backtrack(vector<vector<char>>& board, int iBgn, int jBgn) {
        if (jBgn == 9)
            return backtrack(board, iBgn +1,  0);

        if (iBgn == 9)
            return true;


        for (int i = iBgn; i < 9; ++i) {
            for (int j = jBgn; j < 9; ++j) {
                if (board[i][j] != '.')
                    return backtrack(board, i, j+1);

                for (char c = '1'; c <= '9'; ++c) {
                    if (!isValid(board, i, j, c))
                        continue;

                    board[i][j] = c;

                    if (backtrack(board, i, j + 1))
                        return true;

                    board[i][j] = '.';
                }

                return false;
            }
        }

        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0, 0);
    }
};