// 46. 全排列
// 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
//

#include <vector>

using std::vector;

class Solution {
public:
    void backtrack(vector<int> &nums, int level, vector<vector<int>> &ans){
        // return condition
        // 到最后再入 res （不重复）
        if (level == nums.size() - 1){
            ans.push_back(nums);

            return;
        }

        // 逐逐个交换 头num 与剩余 num
        for (int i = level; i < nums.size(); ++i) {
            std::swap(nums[i], nums[level]);

            backtrack(nums, level+1, ans);

            std::swap(nums[i], nums[level]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(nums, 0, ans);

        return ans;
    }
};