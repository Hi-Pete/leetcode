// 354. 俄罗斯套娃信封问题
// 给你一个二维整数数组 envelopes
// 其中 envelopes[i] = [wi, hi] ，表示第 i 个信封的宽度和高度
// 当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样
// 请计算 最多能有多少个 信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）
// 注意：不允许旋转信封
//

#include <vector>
#include <functional>
#include <algorithm>

using std::vector;

class Solution {
public:
    static bool compareEvlp(vector<int> &env_1, vector<int> env_2) {
        return env_1[0] == env_2[0] ?
               env_2[1] < env_1[1] : env_1[0] < env_2[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        std::sort(envelopes.begin(), envelopes.end(), compareEvlp);

        vector<int> dp(envelopes.size(), 1);
        int max = 0;

        for (int i = 0; i < envelopes.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if(envelopes[j][1] < envelopes[i][1] &&
                   dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;

            }

            max = std::max(max, dp[i]);
        }

        return max;
    }
};