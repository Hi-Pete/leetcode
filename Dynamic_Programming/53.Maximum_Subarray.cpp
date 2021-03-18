// 53. 最大子序和
// 给定一个整数数组 nums ，找到一个具有最大和的连续子数组
// （子数组最少包含一个元素）
// 返回其最大和
//

#include <vector>
#include <limits.h>

using std::vector;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;

        // dp[i] 为以 nums[i] 为结尾的最大子序列
        vector<int> dp(n);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++)
            // dp[i] 为与 dp[i-1]合并的子序列 & 自身 nums[i] 的最大值
            dp[i] = std::max(dp[i-1] + nums[i], nums[i]);

        int res = INT_MIN;
        for(int i = 0; i < n; i++){
            res = std::max(res, dp[i]);
        }
        return res;
    }
};

class compressSol {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;

        // 状态压缩：dp[i] 的值仅与 dp[i-1] 有关
        int dp = 0;
        int dp_i_1 = nums[0];
        int res = dp_i_1;
        for (int i = 1; i < n; i++){
            dp = std::max(dp_i_1 + nums[i], nums[i]);
            dp_i_1 = dp;

            res = std::max(res, dp_i_1);
        }

        return res;
    }
};
