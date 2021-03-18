// 10. 正则表达式匹配
// 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配
//      '.' 匹配任意单个字符
//      '*' 匹配零个或多个前面的那一个元素
// 所谓匹配，是要涵盖 整个字符串 s 的，而不是部分字符串。
//

#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    bool isMatch(string s, string p) {
        unsigned long m = s.size(), n = p.size();

        auto matches = [&](int i, int j) {
            if (i == 0)
                return false;

            if (p[j - 1] == '.')
                return true;

            return s[i - 1] == p[j - 1];
        };

        // dp[i][j] 表示以 i 截止的字符串是否可以被以 j 截止的正则表达式匹配
        // 根据正则表达式的不同情况,即 字符 星号 点号
        // 我们可以分情况讨论来更新 dp 数组
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, false));

        // base case
        dp[0][0] = true;

        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] |= dp[i][j - 2];

                    if (matches(i, j - 1))
                        dp[i][j] |= dp[i - 1][j];
                }
                else
                    if (matches(i, j))
                        dp[i][j] |= dp[i - 1][j - 1];
            }
        }
        return dp[m][n];
    }
};