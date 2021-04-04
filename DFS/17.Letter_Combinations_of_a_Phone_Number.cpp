// 17. 电话号码的字母组合
// 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合
// 答案可以按 任意顺序 返回
//

#include <string>
#include <vector>
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_map;

class Solution {
    unordered_map<char, string> numLetter{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void backtrack(vector<string> &res, string &digits, int idx, string &combination){
        if (idx == digits.size())
            res.push_back(combination);
        else {
            char digit = digits[idx];
            const string &letters = numLetter.at(digit);
            for (const char &letter : letters){
                combination.push_back(letter);

                backtrack(res, digits, idx +1, combination);

                combination.pop_back();
            }
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(!digits.size())
            return res;

        string combination;
        backtrack(res, digits, 0, combination);

        return res;
    }
};