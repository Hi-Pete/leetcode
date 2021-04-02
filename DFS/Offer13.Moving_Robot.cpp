// 剑指 Offer 13. 机器人的运动范围
// 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1]
// 一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格
// 不能移动到方格外，也不能进入行坐标和列坐标的数位之和大于k的格子
// 例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18
// 但它不能进入方格 [35, 38]，因为3+5+3+8=19
// 请问该机器人能够到达多少个格子
//

#include <vector>

using std::vector;

class Solution {
    int getDigitSum(int num){
        int sum = 0;
        while (num > 0){
            sum += num%10;
            num /= 10;
        }

        return sum;
    }

    int dfs(int m, int n, int k, int row, int col,
            vector<vector<bool>> &visited)
    {
        if(row  < m && col < n &&
           getDigitSum(row) + getDigitSum(col) <= k &&
           !visited[row][col])
        {
            visited[row][col] = true;

            return 1 + dfs(m, n, k, row +1, col, visited) +
                   dfs(m, n, k, row, col +1, visited);
        } else
            return 0;
    }
public:
    int movingCount(int m, int n, int k) {
        if (m <= 0 || n <= 0 || k < 0)
            return 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int res = 0;

        return dfs(m, n, k, 0, 0, visited);
    }
};


