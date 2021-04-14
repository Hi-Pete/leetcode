// 3. 无重复字符的最长子串
// 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度
//

#include <string>
#include <unordered_set>
#include <unordered_map>

using std::string;
using std::unordered_set;
using std::unordered_map;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int max = 0;

        for (int i = 0, j = 0; i < j ; ++i) {
            while (set.find(s[j]) != set.end()){
                set.erase(s[j]);
                i++;
            }

            set.insert(s[j]);
            max = std::max(max, (int)set.size());
        }

        return max;
    }

    int lengthOfLongestSubstring_map(string s) {
        unordered_map<char, int> map;
        int max = 0;

        for (int i = 0, j = 0; j < s.size() ; ++j) {
            if (map.find(s[j]) != map.end()){
                int idx = map.find(s[j])->second;
                i = std::max(i, idx + 1);
            }

            map.insert(std::make_pair(s[j], j));
            max = std::max(max, j - i + 1);
        }

        return max;
    }
};