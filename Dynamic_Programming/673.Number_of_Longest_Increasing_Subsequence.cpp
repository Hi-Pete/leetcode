// 673. 最长递增子序列的个数
// 给定一个未排序的整数数组，找到最长递增子序列的个数
//

#include <vector>

using std::vector;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        // count[i] 表示以 i 结尾的最长子序列长度出现的个数
        vector<int> count(nums.size(), 1);
        int max = 0;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j){
                if (nums[j] >= nums[i])
                    continue;

                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                } else if (dp[i] == dp[j] + 1){
                    count[i] += count[j];
                }
            }

            max = std::max(max, dp[i]);
        }

        int res = 0;
        for (int k = 0; k < nums.size(); ++k) {
            if (dp[k] == max){
                res += count[k];
            }
        }

        return res;
    }
};