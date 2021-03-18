// 64. 最小路径和
// 给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小
// 说明：每次只能向下或者向右移动一步。
//

#include <vector>

using std::vector;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;

        unsigned long m = grid.size(), n = grid[0].size();

        // dp[i][j] 表示从左上角开始到 (i, j) 位置的最优路径的数字和
        // 因为每次只能向下或者向右移动,我们可以很容易得到状态转移方程
        // dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
        // 其中 grid 表示原数组
        vector<vector<int>> dp(m, vector<int> (n, 0));

        /******** base case *******/
        dp[0][0] = grid[0][0];

        for (int j = 1; j < n; ++j)
            dp[0][j] = dp[0][j-1] + grid[0][j];

        for (int i = 1; i < m; ++i)
            dp[i][0] = dp[i-1][0] + grid[i][0];
        /**************************/

        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                dp[i][j] = std::min(dp[i-1][j], dp[i][j-1]) + grid[i][j];

        return dp[m-1][n-1];
    }
};