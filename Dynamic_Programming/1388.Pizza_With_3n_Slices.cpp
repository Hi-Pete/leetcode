// 1388. 3n 块披萨
// 给你一个披萨，它由 3n 块不同大小的部分组成，现在你和你的朋友们需要按照如下规则来分披萨：
//      你挑选 任意 一块披萨
//      Alice 将会挑选你所选择的披萨逆时针方向的下一块披萨
//      Bob 将会挑选你所选择的披萨顺时针方向的下一块披萨
//      重复上述过程直到没有披萨剩下
// 每一块披萨的大小按顺时针方向由循环数组 slices 表示
// 请你返回你可以获得的披萨大小总和的最大值
//

#include <vector>

using std::vector;

class Solution {
    int dp(vector<int> &slices, int bgn, int end){
        int nSlice = end - bgn +1;
        int n = (nSlice + 1)/3;
        vector<vector<int>> dp(nSlice+1, vector<int>(n+1, 0));
        for (int i = 1; i <= nSlice; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i >= 2)
                    dp[i][j] = std::max(dp[i-1][j], dp[i-2][j-1] + slices[bgn + i-1]);
                else
                    dp[i][j] = std::max(dp[i-1][j], slices[bgn+ i-1]);
            }
        }
        return dp[nSlice][n];
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        if (slices.size() == 0)
            return 0;
        int sz = slices.size();
        return std::max(dp(slices, 0, sz-2), dp(slices, 1, sz-1));
    }
};

int main() {
    vector<int> nums = {1,2,3,4,5,6};

    Solution solver;
    solver.maxSizeSlices(nums);

    return 0;
}

