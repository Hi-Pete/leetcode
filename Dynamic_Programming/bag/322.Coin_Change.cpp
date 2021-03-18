// 322. 零钱兑换
// 给定不同面额的硬币 coins 和一个总金额 amount
// 编写一个函数来计算可以凑成总金额所需的最少的硬币个数
// 如果没有任何一种硬币组合能组成总金额，返回 -1
// 你可以认为每种硬币的数量是无限的
//

#include <vector>

using std::vector;

class Solution {
    int coinChange(vector<int>& coins, int amount) {
        if (coins.empty())
            return -1;

        // dp[i] 表示当金额为 i 时至少需要多少枚金币
        // 由于后面要进行最小值比较
        // 所以这里不能初始化为 -1
        vector<int> dp(amount+1, amount+2);

        // base case
        dp[0] = 0;

        for (int i = 1; i < amount + 1; ++i)
            for (const int &coin : coins)
                if (i-coin >= 0)
                    // 不取该硬币则剩余金额仍为 i , 取该硬币则 dp + 1 , 金额数 - coin
                    dp[i] = std::min(dp[i], 1+dp[i-coin]);

        return (dp[amount] == amount + 2) ? -1 : dp[amount];
    }
};