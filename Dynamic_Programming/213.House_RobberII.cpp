// 213. 打家劫舍 II
// 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金
// 这个地方所有的房屋都围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的
// 同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警
// 给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，能够偷窃到的最高金额
//

#include <vector>

using std::vector;

class Solution {
public:
    int robRange(vector<int>& nums, int bgn, int end){
        int dp_2 = 0;
        int dp_1 = 0;
        int ans = 0;
        for (int i = bgn; i <= end; i++) {
            // 状态转移方程
            ans = std::max(dp_2 + nums[i], dp_1);
            dp_2 = dp_1;
            dp_1 = ans;
        }

        return ans;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        // base case
        if (n==0)
            return 0;
        if (n==1)
            return nums[0];

        // 首尾不能同时选，就分成两种情况比最大
        return std::max(robRange(nums, 0, n-2), robRange(nums, 1, n-1));
    }
};


