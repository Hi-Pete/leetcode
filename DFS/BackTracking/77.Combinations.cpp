// 77. 组合
// 给定两个整数 n 和 k
// 返回 1 ... n 中所有可能的 k 个数的组合
//



#include <vector>

using std::vector;

class Solution {
    vector<vector<int>> res;

    void backtrack(int n, int k, int start, vector<int> &track){
        if (track.size() == k){
            res.push_back(track);

            return;
        }

        for (int i = start; i <= n; ++i) {
            track.push_back(i);

            backtrack(n, k, i+1, track);

            track.pop_back();
        }
    }

public:
    // 典型的回溯算法：
    //      k 限制了树的高度
    //      n 限制了树的宽度
    vector<vector<int>> combine(int n, int k) {
        if (n<=0 || k<=0)
            return res;

        vector<int> track;
        backtrack(n, k, 1, track);

        return res;
    }
};