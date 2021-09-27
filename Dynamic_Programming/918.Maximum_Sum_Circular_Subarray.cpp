// 918. 环形子数组的最大和
// 给定一个由整数数组 A 表示的环形数组 C，求 C 的非空子数组的最大可能和
//

#include <vector>

using std::vector;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int curMax = 0, curMin = 0, max = A[0], min = A[0], sum = 0;

        for(int a: A) {
            sum += a;

            curMax = std::max(a, curMax + a);
            max = std::max(max, curMax);

            curMin = std::min(a, curMin + a);
            min = std::min(min, curMin);
        }

        return max < 0 ? max : std::max(max, sum - min);
    }
};