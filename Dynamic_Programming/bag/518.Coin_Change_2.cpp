// 518. 零钱兑换 II
// 给定不同面额的硬币和一个总金额
// 写出函数来计算可以凑成总金额的硬币组合数
// 假设每一种面额的硬币有无限个
//

#include <vector>

using std::vector;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // 若只使用 coins 中的前 i 个硬币的面值，若想凑出金额 j，有dp [i][j] 种凑法
        // base case : dp[0][..] = 0 , dp[..][0] = 1
        // target : dp[N][amount]
        unsigned long n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));

        for (int i = 0; i < n + 1; ++i)
            dp[i][0] = 1;

        for (int i = 1; i < n+1; ++i)
            for (int j = 1; j < amount+1; ++j) {
                if (coins[i-1] <= j)
                    // 使用当前硬币或不使用
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
                else
                    // 待凑总金额小于硬币面额，无法使用当前硬币
                    dp[i][j] = dp[i-1][j];
            }

        return dp[n][amount];
    }
};