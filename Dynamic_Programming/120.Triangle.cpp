// 120. 三角形最小路径和
// 给定一个三角形 triangle ，找出自顶向下的最小路径和
// 每一步只能移动到下一行中相邻的结点上
// 相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点
// 就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1
//

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0)
            return 0;

        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = dp[i-1][0] + triangle[i][0];
            for (int j = 1; j < i; ++j) {
                dp[i][j] = std::min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
            }
            dp[i][i] = dp[i-1][i-1] + triangle[i][i];
        }

        return *std::min_element(dp[n-1].begin(), dp[n-1].end());
    }
};

