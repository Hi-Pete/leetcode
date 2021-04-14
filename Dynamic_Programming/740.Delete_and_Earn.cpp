// 740. 删除与获得点数
// 给定一个整数数组 nums ，你可以对它进行一些操作
// 每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数
// 之后，你必须删除每个等于 nums[i] - 1 或 nums[i] + 1 的元素
// 开始你拥有 0 个点数
// 返回你能通过这些操作获得的最大点数
//

#include <vector>

using std::vector;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(!nums.size())
            return 0;

        int n = nums.size();
        if (nums.size() == 1)
            return nums[0];

        int max = 0;
        for (int i = 0; i < n; ++i) {
            max = std::max(max, nums[i]);
        }

        vector<int> bucket(max + 1, 0);
        for (int num : nums)
            bucket[num]++;

        int dp_2 = 0, dp_1 = 0;
        int res = 0;
        for (int j = 0; j <= max; ++j) {
            res = std::max(dp_2 + j*bucket[j], dp_1);
            dp_2 = dp_1;
            dp_1 = res;
        }

        return res;
    }
};