// 415. 字符串相加
// 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和
//

#include <string>
#include <algorithm>

using std::string;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1, j = num2.size() - 1;
        int add_flag = 0;
        string res_v;

        while (i>=0 || j>=0 || add_flag){
            int n1 = (i>=0) ? (num1[i--] - '0') : 0;
            int n2 = (j>=0) ? (num2[j--] - '0') : 0;
            int res =  n1 + n2 + add_flag;

            if (res>=10){
                add_flag = 1;
                res = res - 10;
            } else
                add_flag = 0;

            res_v += std::to_string(res);
        }
        std::reverse(res_v.begin(), res_v.end());

        return res_v;
    }
};