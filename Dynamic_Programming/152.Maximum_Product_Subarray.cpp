// 152. 乘积最大子数组
// 给你一个整数数组 nums ，请你找出数组中乘积最大的 连续子数组
// （该子数组中至少包含一个数字）
// 并返回该子数组所对应的乘积。
//

#include <vector>
#include <algorithm>

using std::vector;
using std::min;
using std::max;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        vector<int> maxF(nums), minF(nums);
        for (int i = 1; i < nums.size(); ++i) {
            maxF[i] = max(maxF[i - 1] * nums[i], max(nums[i], minF[i - 1] * nums[i]));
            minF[i] = min(minF[i - 1] * nums[i], min(nums[i], maxF[i - 1] * nums[i]));
        }
        return *max_element(maxF.begin(), maxF.end());
    }
};

class Solution_ {
public:
    int maxProduct(vector<int> &nums) {
        // 循环外定义 maxN 和 minN 两个全局变量，记录上一次的最大值最小值
        int maxN=nums[0], minN=nums[0];
        // 用来在循环中保留最大值
        int ans = nums[0];
        // 注意从 1 开始，不然nums[0]
        for (int i = 1; i < nums.size(); ++i) {
            int mx=maxN, mn=minN;
            maxN = max(mx * nums[i], max(nums[i], mn * nums[i]));
            minN = min(mn * nums[i], min(nums[i], mx * nums[i]));

            ans = max(ans, maxN);
        }

        return ans;
    }
};

int main(){
    vector<int> nums = {2,3,-2,4};
    Solution_ sol;
    int res = sol.maxProduct(nums);

    return 0;
}