// 22. 括号生成
// 数字 n 代表生成括号的对数
// 请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合
//

#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
    void backtrack(int left, int right,
                   string &track, vector<string> &res) {
        if (right < left)
            return;

        if (right < 0 || left < 0)
            return;

        if (left==0 && right==0){
            res.push_back(track);

            return;
        }

        track.push_back('(');
        backtrack(left-1, right, track, res);
        track.pop_back();

        track.push_back(')');
        backtrack(left, right-1, track, res);
        track.pop_back();
    }
public:
    vector<string> generateParenthesis(int n) {
        if (n==0)
            return {};

        vector<string> res;
        string track;

        backtrack(n, n, track, res);

        return res;
    }
};