// 70. 爬楼梯
// 假设你正在爬楼梯, 需要 n 阶你才能到达楼顶
// 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
//
// 注意：给定 n 是一个正整数。
//

class Solution {
public:
    int climbStairs(int n) {
        if (n<=2)
            return n;

        int n_1 = 2, n_2 = 1, res = 0;
        for(int i = 3; i <= n; i++){
            res = n_1 + n_2;
            n_2 = n_1;
            n_1 = res;
        }
        return res;
    }
};