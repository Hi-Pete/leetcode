// 516. 最长回文子序列
// 给定一个字符串 s ，找到其中最长的回文子序列，并返回该序列的长度
// 可以假设 s 的最大长度为 1000
//

#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        unsigned long n = s.size();
        // dp[i][j] 代表子串 s[i..j] 中，最长回文子序列的长度
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; ++i)
            dp[i][i] = 1;

        for (int len = 2; len <= n; len++){
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len -1;
                // 状态转移方程
                if (s[i]==s[j])
                    dp[i][j] = dp[i+1][j-1] + 2;
                else
                    dp[i][j] = std::max(dp[i+1][j], dp[i][j-1]);
            }
        }

        return dp[0][n-1];
    }
};