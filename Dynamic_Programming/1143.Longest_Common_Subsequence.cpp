// 1143. 最长公共子序列
// 给定两个字符串 text1 和 text2
// 返回这两个字符串的最长公共子序列的 长度
// 一个字符串的子序列 是指这样一个新的字符串：
// 它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串
// 例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列
// 两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列
// 若这两个字符串没有公共子序列，则返回 0
//

#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    /**
     * 定义一个 dp 数组,其中 dp[i] 表示到位置 i 为止的子序列的性质,并不必须以 i 结尾
     * 这样 dp 数组的最后一位结果即为题目所求,不需要再对每个位置进行统计
     * 在本题中,我们可以建立一个二维数组 dp
     * 其中 dp[i][j] 表示到第一个字符串位置 i 为止、到第二个字符串位置 j 为止、最长的公共子序列长度
     * 这样一来我们就可以很方便地分情况讨论这两个位置对应的字母相同与不同的情况了
     * @param text1
     * @param text2
     * @return length of longest common subsequence
     */
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.empty() || text2.empty())
            return 0;

        unsigned long l1 = text1.size(), l2 = text2.size();
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
        // 定义：text1[0..i-1] 和 text2[0..j-1] 的 lcs 长度为 dp[i][j]
        // 目标：text1[0..m-1] 和 text2[0..n-1] 的 lcs 长度，即 dp[m][n]
        // 即， dp 下标为长度

        // base case: dp[0][..] = dp[..][0] = 0
        for (int i = 1; i <= l1; ++i) {
            for (int j = 1; j <= l2; ++j) {
                if (text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[l1][l2];
    }
};