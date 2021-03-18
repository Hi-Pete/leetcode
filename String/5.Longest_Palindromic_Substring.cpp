// 5. 最长回文子串
// 给你一个字符串 s，找到 s 中最长的回文子串
//

#include <string>

using std::string;

class Solution {
public:
    string palindrome(string& s, int l, int r){
        // 防止索引越界
        while (l>=0 && r<s.size() && s[l] == s[r]){
            l--;
            r++;
        }

        return s.substr(l+1, r-l-1);
    }

    string longestPalindrome(string s) {
        string res;
        for (int i = 0; s.size() > i ; ++i) {
            string s1 = palindrome(s, i, i);
            string s2 = palindrome(s, i, i+1);

            res = res.size() > s1.size() ? res : s1;
            res =  res.size() > s2.size() ? res : s2;
        }

        return res;
    }
};