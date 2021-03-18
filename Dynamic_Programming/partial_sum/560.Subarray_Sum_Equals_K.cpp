// 560. 和为K的子数组
// 给定一个整数数组和一个整数 k
// 你需要找到该数组中和为 k 的连续的子数组的个数
// 说明 :
//      数组的长度为 [1, 20,000]
//      数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]
//

#include <vector>
#include <unordered_map>

using std::vector;

class Solution {
  public:
    // 使用一个哈希表 preSum_count,其键是前缀和,而值是该前缀和出现的次数
    // 要求满足 preSum[i] - preSum[j] == k 的区间
    // 即 preSum[j] == preSum[i] - k
    // 只需要记录有几个 preSum[j] 和 preSum[i]-k 相等
    // 就有几个区间和为 k
    // 在我们遍历到位置 i 时,假设当前的前缀和是 preSum
    // 那么 preSum_count[preSum - k] 即为以当前位置结尾、满足条件的区间个数
    int subarraySum(vector<int>& nums, int k) {
        unsigned long n = nums.size();
        std::unordered_map<int, int> preSum_count;

        int preSum = 0, count = 0;
        // base case
        preSum_count[0] = 1;

        for (int i = 0; i < n; i++){
            // 计算当前位置前缀和 preSum[i]
            preSum += nums[i];

            // 计算前面有多少前缀和 preSum[j] 和满足 preSum[j] == preSum[i] - k
            count += preSum_count[preSum - k];

            ++preSum_count[preSum];
        }

        return count;
    }
};