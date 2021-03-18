// 91. 解码方法
// 一条包含字母 A-Z 的消息通过以下映射进行了编码：
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// 要解码已编码的消息，所有数字必须基于上述映射的方法，反向映射回字母（可能有多种方法）
// 例如，"111" 可以将 "1" 中的每个 "1" 映射为 "A" ，从而得到 "AAA"
// 或者可以将 "11" 和 "1"（分别为 "K" 和 "A" ）映射为 "KA"
// 注意，"06" 不能映射为 "F" ，因为 "6" 和 "06" 不同
// 给你一个只含数字的非空字符串 num ，请计算并返回解码方法的总数
// 题目数据保证答案肯定是一个 32 位 的整数
//

#include <string>
#include <vector>

using std::string
using std::vector

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (n == 0)
            return 0;

        int prev = s[0] - '0';
        // 开头为 0 的字符串无法解码
        if (!prev)
            return 0;
        if (n == 1)
            return 1;

        vector<int> dp(n + 1, 1);
        for (int i = 2; i <= n; ++i) {
            int cur = s[i-1] - '0';

            // 出现 0 开头的子字符串，无法解码
            if ((prev == 0 || prev > 2) && cur == 0)
                return 0;

            // 考虑和前一位结合解码
            if ((prev < 2 && prev > 0) || prev == 2 && cur < 7) {
                if (cur)
                    dp[i] = dp[i-2] + dp[i-1];
                else
                    // curr 为 0 的话只能和前一位结合增加解码数量
                    dp[i] = dp[i-2];
            } else
                // 前面的解码序列结尾加这一个数而已，不增加解码数量
                dp[i] = dp[i-1];

            prev = cur;
        }
        return dp[n];
    }
};
