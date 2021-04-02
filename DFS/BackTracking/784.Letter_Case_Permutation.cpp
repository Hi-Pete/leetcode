// 784. 字母大小写全排列
// 给定一个字符串S
// 通过将字符串S中的每个字母转变大小写，我们可以获得一个新的字符串
// 返回所有可能得到的字符串集合
//

#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution {
    string strRes(vector<int> &letterIdx, vector<int> track, string S) {
        for (int i = 0; i < track.size(); ++i) {
            int idx = letterIdx[track[i]];
            S[idx] ^= ' ';
        }

        return S;
    }

    void backtrack(vector<int> &letterIdx, vector<int> &track,
                   string S, int bgn,
                   vector<string> &res) {
        int n = letterIdx.size();
        res.push_back(strRes(letterIdx, track, S));

        for (int i = bgn; i < n; ++i) {
            track.push_back(i);

            backtrack(letterIdx, track, S, i +1, res);

            track.pop_back();
        }
    }

public:
    vector<string> letterCasePermutation(string S) {
        vector<int> letterIdx;
        vector<int> track;
        vector<string> res;

        for (int i = 0; i < S.size(); ++i)
            if(isalpha(S[i]))
                letterIdx.push_back(i);

        backtrack(letterIdx, track, S, 0, res);

        return res;
    }
};

int main() {
    string str = "a1b2";

    Solution solver;
    solver.letterCasePermutation(str);

    return 0;
}