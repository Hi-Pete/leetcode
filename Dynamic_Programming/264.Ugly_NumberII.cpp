// 264. 丑数 II
// 编写一个程序，找出第 n 个丑数
// 丑数就是质因数只包含 2, 3, 5 的正整数
//

#include <vector>;

using std::vector;

class Solution {
    int Min(int a, int b, int c) {
        return std::min(a, std::min(b, c));
    }
public:
    int nthUglyNumber(int n) {
        vector<int> uglyNums(n);
        uglyNums[0] = 1;
        int nextIdx = 1;

        int x2Idx = 0, x3Idx = 0, x5Idx = 0;
        while (nextIdx < n) {
            int min = Min(uglyNums[x2Idx] *2, uglyNums[x3Idx] *3, uglyNums[x5Idx] *5) ;
            uglyNums[nextIdx] = min;

            while (uglyNums[x2Idx] *2 <= uglyNums[nextIdx])
                x2Idx++;
            while (uglyNums[x3Idx] *3 <= uglyNums[nextIdx])
                x3Idx++;
            while (uglyNums[x5Idx] *5 <= uglyNums[nextIdx])
                x5Idx++;

            nextIdx++;
        }

        return uglyNums[nextIdx-1];
    }
};

int main(){
    Solution solver;
    int res = solver.nthUglyNumber(10);

    return 0;
}