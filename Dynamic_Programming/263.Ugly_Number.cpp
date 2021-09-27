// 263. 丑数
// 给你一个整数 n ，请你判断 n 是否为 丑数
// 如果是，返回 true ；否则，返回 false
// 丑数 就是只包含质因数 2、3 和/或 5 正整数
//

#include <vector>

using std::vector;

class Solution {
public:
    bool isUgly(int n) {
        if (n == 0)
            return false;
        vector<int> uglyNums = {2, 3, 5};

        for(int uglyNum: uglyNums)
            while ( n % uglyNum == 0)
                n /= uglyNum;

        return (n == 1);
    }
};