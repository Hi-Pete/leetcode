// 72. 编辑距离
// 给你两个单词 word1 和 word2
// 请你计算出将 word1 转换成 word2 所使用的最少操作数 
// 你可以对一个单词进行如下三种操作：
//      插入一个字符
//      删除一个字符
//      替换一个字符
//

#include <vector>
#include <string>

using std::vector;
using std::string;

using std::min;

class Solution {
public:
    int minDistance(string word1, string word2) {
        // dp[i][j] 表示将第一个字符串到位置 i 为止,和第二个字符串到位置 j 为止,最多需要几步编辑
        // i j 在 dp 数组中代表字符串长度
        // base case:
        //      1. j 走完 word2 时, 如果 i 还没走完 word1 ，那么只能用删除操作把 word1 缩短为 word2
        //      2. i 走完 word1 时, 如果 j 还没走完 word2 ，那就只能用插入操作把 word2 剩下的字符全部插入 word1

        // 当第 i 位和第 j 位对应的字符相同时, dp[i][j] 等于 dp[i-1][j-1];
        // 当二者对应的字符不同时, 替换的消耗是 dp[i-1][j-1] + 1
        //      插入 i 位置/删除 j 位置的消耗是 dp[i][j-1] + 1
        //      插入 j 位置/删除 i 位置的消耗是 dp[i-1][j] + 1

        unsigned long l1 = word1.size(), l2 = word2.size();
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));

        // base case
        for (int i = 1; i <= l1; ++i)
            dp[i][0] = i;
        for (int j = 1; j <= l2; ++j)
            dp[0][j] = j;

        for (int i = 1; i <= l1 ; ++i)
            for (int j = 1; j <= l2 ; ++j) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
            }

        return dp[l1][l2];
    }
};