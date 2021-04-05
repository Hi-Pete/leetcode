// 300. 最长递增子序列
// 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度
// 子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序
// 例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列
//

#include <vector>
#include <map>

using std::vector;
using std::map;

class Top_Down {
    // dp[i] := 在子数组 [0..i] 上，且选了 nums[i] 时，的最长上升子序列
  public:
    int max;
    // 备忘录
    map<int, int> cache;

    int dp(vector<int>& nums, int n) {
        // Memoization
        if (cache.find(n) != cache.end())
            return cache[n];

        // base case
        if (n<=1)
            return n;

        int maxEndingHere = 1;
        for (int i = 1; i < n ; i++) {
            // 计算 nums 中前 i 位的最长递增子序列
            int result = dp(nums, i);    // 重复子问题

            // 最后一个数必须包含在 f(n) 子序列中
            // 满足则将结果 + 1（不用遍历最后一个元素）
            // 注意这里是有可能 maxEndingHere(前面的结果) > result+1 的
            // result 因为必须要选当前最后一位数，可能要舍弃长度
            if (nums[i-1] < nums[n-1] &&
                result +1 > maxEndingHere)
                maxEndingHere = result + 1;
        }

        max = (max < maxEndingHere)? maxEndingHere : max;

        cache.insert({n, maxEndingHere});

        return maxEndingHere;
    }

    int lengthOfLIS(vector<int>& nums) {
        if (!nums.size())
            return 0;

        max = 1;
        dp(nums, nums.size());

        return max;
    }
};

class Bottom_Up{
public:
    int lengthOfLIS(vector<int>& nums){
        vector<int> cache(nums.size(), 1);
        int max = 0;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j)
                // 比较 nums[i] 之前的数是否比它小
                // 以及判断 cache[j] 的值是否比当前 cache[i] 大
                // 例如，nums[j] 比之前所有的数都小，cache[j]就可能小于当前 cache[i]
                if (nums[j] < nums[i] && cache[i] < cache[j] + 1)
                    cache[i] = cache[j] + 1;

            // 在记录数组的过程中把 max 比较出来
            max = std::max(max, cache[i]);
        }

        return max;
    }
};