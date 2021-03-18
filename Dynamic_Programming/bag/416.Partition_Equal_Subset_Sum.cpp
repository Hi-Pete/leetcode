// 416. 分割等和子集
// 给定一个只包含正整数的非空数组
// 是否可以将这个数组分割成两个子集，使得两个子集的元素和相等
//

#include <numeric>

#include <vector>

using std::vector;

class Solution {
public:
    // 本题等价于 0-1 背包问题
    // 设所有数字和为 sum, 我们的目标是选取一部分物品, 使得它们的总和为 sum/2
    // 即，给一个可装载重量为 sum/ 2的背包和 N 个物品，是否存在一种装法，能够恰好将背包装满
    // 这道题不需要考虑价值,因此我们只需要通过一个布尔值矩阵来表示状态转移矩阵
    // 注意边界条件的处理
    bool canPartition(vector<int>& nums) {
        // dp[i][w] 表示对前 i 个物品进行选择，当前背包的容量为 w 时可以装的最大价值
        // base case : i = 0 || w = 0 时 dp[i][w] 均为 0
        //
        // 而这里不需要考虑价值 w ，只考虑能否装满，所以 dp 设为一个 bool 矩阵
        // dp[i][j] = x 表示，对于前i个物品，当前背包的容量为 j 时
        //      若x为true，则说明可以恰好将背包装满
        //      若x为false，则说明不能恰好将背包装满
        // base case :  dp[..][0] = true , dp[0][..] = false
        // 目标 ：       dp[N][sum/2]
        //
        unsigned long n = nums.size();
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum%2)
            return false;

        int target = sum/2;

        vector<vector<bool >> dp(n + 1, vector<bool>(target + 1, false));

        // base case
        for (int i = 0; i < n+1; ++i)
            dp[i][0] = true;

        for (int i = 1; i <= n; ++i) {
            for (int j = nums[i-1]; j <= target ; ++j) {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
        }

        return dp[n][target];
    }
};

// 状态空间压缩
class Compress_Sol{
  public:
    bool canPartition(vector<int>& nums){
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum%2)
            return false;

        int target = sum/2,  n = nums.size();

        vector<bool> dp(target, false);

        // base case
        dp[0] = true;

        for (int i = 1; i <= n; ++i)
            for (int j = target; j >= nums[i-1]; --j)
                dp[j] = dp[j] || dp[j-nums[i-1]];

        return dp[target];
    }
};