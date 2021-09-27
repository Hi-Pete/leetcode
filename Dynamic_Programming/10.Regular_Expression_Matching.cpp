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

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, false));

        // base case
        dp[0][0] = true;

        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j -2];
                    if (matches(i, j - 1))
                        dp[i][j] |= dp[i-1][j];
                } else
                if (matches(i, j))
                    dp[i][j] = dp[i - 1][j - 1];
            }
        }
        return dp[m][n];
    }
};

int main() {
    string str1 = "aa", str2 = "a*";
    Solution solver;
    bool res = solver.isMatch(str1, str2);

    return 0;
}