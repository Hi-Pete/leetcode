// 221. 最大正方形
// 在一个由 '0' 和 '1' 组成的二维矩阵内
// 找到只包含 '1' 的最大正方形，并返回其面积
//

#include <vector>

using std::vector;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // dp[i][j] 表示 以 (i, j) 为右下角的全由 1 构成的最大正方形面积
        // 如果当前位置是 0,那么 dp[i][j] 即为 0
        // 如果当前位置是 1,我们假设 dp[i][j] = k^2
        // 其充分条件为 dp[i-1][j-1]、 dp[i][j-1] 和 dp[i-1][j] 的值必须都不小于 (k − 1)^2
        // 否则 (i, j) 位置不可以构成一个边长为 k 的正方形
        if (matrix.empty() || matrix[0].empty())
            return 0;

        unsigned long m = matrix.size(), n = matrix[0].size();
        int max_side = 0;
        vector<vector<int>> dp(m, vector<int> (n, 0));

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    if ( i == 0 || j == 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = std::min(dp[i - 1][j - 1], std::min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }

                max_side = std::max(max_side, dp[i][j]);
            }

        return max_side*max_side;
    }
};