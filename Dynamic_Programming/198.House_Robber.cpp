// 198. 打家劫舍
// 你是一个专业的小偷, 计划偷窃沿街的房屋, 每间房内都藏有一定的现金
// 影响你偷窃的唯一制约因素就是 相邻的房屋装有相互连通的防盗系统
// 如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警
// 给定一个代表每个房屋存放金额的非负整数数组
// 计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额
//
#include <vector>

using std::vector;

#include <vector>

using std::vector;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        // base case
        if (n==0)
            return 0;
        if (n==1)
            return nums[0];

        int dp_2 = nums[0];
        int dp_1 = std::max(dp_2, nums[1]);
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            // 状态转移方程
            ans = std::max(dp_2 + nums[i], dp_1);
            dp_2 = dp_1;
            dp_1 = ans;
        }

        return ans;
    }

    int rob_2(vector<int>& nums) {
        int n = nums.size();

        // base case
        if (n==0)
            return 0;
        if (n==1)
            return nums[0];

        int dp_2 = 0;
        int dp_1 = nums[0];
        int ans = 0;
        for (int i = 2; i <= n; i++) {
            // 状态转移方程
            ans = std::max(dp_2 + nums[i-1], dp_1);
            dp_2 = dp_1;
            dp_1 = ans;
        }

        return ans;
    }
};
