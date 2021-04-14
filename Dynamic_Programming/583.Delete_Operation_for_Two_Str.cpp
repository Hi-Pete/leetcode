// 583. 两个字符串的删除操作
// 给定两个单词 word1 和 word2
// 找到使得 word1 和 word2 相同所需的最小步数
// 每步可以删除任意一个字符串中的一个字符
//

#include <vector>
#include <string>
#include <iostream>

using std::string;
using std::vector;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        // find LCS
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n ; ++j) {
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else{
                    dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return m - dp[m][n] + n - dp[m][n];
    }
};

int main(){
    string str1, str2;
    std::cin >> str1;
    std::cin >> str2;

    Solution solver;
    int res = solver.minDistance(str1, str2);

    std::cout << res;

    return 0;
}