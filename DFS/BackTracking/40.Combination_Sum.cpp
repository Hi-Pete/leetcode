//
// Created by bigfat on 2021/4/4.
//

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
    void backtrack(vector<int> &candidates,
                   int bgn, int n,
                   int target, vector<bool> &used,
                   vector<int> &path, vector<vector<int>> &res){
        if(target == 0) {
            res.push_back(path);

            return;
        }

        for (int i = bgn; i < n; ++i) {
            // 如果减去一个数的值小于 0 ，就没有必要再减去更大的数
            if (target - candidates[i] < 0)
                break;

            if (i>0 && candidates[i] == candidates[i-1] && !used[i-1])
                continue;

            path.push_back(candidates[i]);
            used[i] = true;

            backtrack(candidates, i+1, n, target - candidates[i], used, path, res);

            path.pop_back();
            used[i] = false;
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if(candidates.size()==0)
            return res;

        int n = candidates.size();

        std::sort(candidates.begin(), candidates.end());
        vector<int> path;
        vector<bool> used(n, false);

        backtrack(candidates, 0, n, target, used, path, res);

        return res;
    }
};