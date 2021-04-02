// 39. 组合总和
// 给定一个无重复元素的数组 candidates 和一个目标数 target 
// 找出 candidates 中所有可以使数字和为 target 的组合
// candidates 中的数字可以无限制重复被选取
//

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
    void backtrack(vector<int> &candidates,
                   int bgn, int n,
                   int target,
                   vector<int> &path, vector<vector<int>> &res){
        if(target == 0) {
            res.push_back(path);

            return;
        }

        for (int i = bgn; i < n; ++i) {
            // 如果减去一个数的值小于 0​ ，就没有必要再减去更大的数
            if (target - candidates[i] < 0)
                break;

            path.push_back(candidates[i]);

            // 注意：由于每一个元素可以重复使用，下一轮搜索的起点依然是 i
            backtrack(candidates, i, n, target-candidates[i], path, res);

            path.pop_back();
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

        backtrack(candidates, 0, n, target, path, res);

        return res;
    }
};