// 51. N 皇后
// n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击
// 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案
// 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位
//

#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    void backtrack(vector<vector<string>> &ans, vector<string> &board,
                   vector<bool> &column,    // 按引用传状态
                   vector<bool> &ldiag, vector<bool> &rdiag, int row, int n){
        // return case
        if (row == n){
            ans.push_back(board);
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (column[i] || ldiag[n-row+i-1] || rdiag[row+i+1])
                continue;

            // 修改状态
            board[row][i] = 'Q';
            column[i] = ldiag[n-row+i-1] = rdiag[row+i+1] = true;

            backtrack(ans, board, column, ldiag, rdiag, row+1, n);

            // 回溯
            board[row][i] = '.';
            column[i] = ldiag[n-row+i-1] = rdiag[row+i+1] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        if (n==0)
            return ans;

        vector<string> board(n, string(n, '.'));
        vector<bool> colunm(n, false), ldiag(2*n-1, false), rdiag(2*n-1, false);

        backtrack(ans, board, colunm, ldiag, rdiag, 0, n);

        return ans;
    }
};