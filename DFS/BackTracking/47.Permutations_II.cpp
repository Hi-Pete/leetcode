// 47. 全排列 II
// 给定一个可包含重复数字的序列 nums
// 按任意顺序 返回所有不重复的全排列
//

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
    void  backtrack(vector<int> &nums, int index, int n,
                    vector<bool> &vbUsed, vector<int> &path,
                    vector<vector<int>> &res) {
        if(index == n){
            res.push_back(path);

            return;
        }

        for (int i = 0; i < n; ++i) {
            if (vbUsed[i])
                continue;

            if(i > 0 && nums[i] == nums[i-1] && !vbUsed[i - 1])
                continue;

            vbUsed[i] = true;
            path.push_back(nums[i]);

            backtrack(nums, index +1, n, vbUsed, path, res);

            vbUsed[i] = false;
            path.pop_back();
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() ==0)
            return res;

        int n = nums.size();
        vector<bool> vbUsed(n, false);
        vector<int> path;

        std::sort(nums.begin(), nums.end());

        backtrack(nums, 0, n, vbUsed, path, res);

        return res;
    }
};