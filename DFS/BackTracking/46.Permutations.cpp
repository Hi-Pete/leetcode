// 46. 全排列
// 给定一个 没有重复 数字的序列
// 返回其所有可能的全排列
//

#include <vector>

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

            vbUsed[i] = true;
            path.push_back(nums[i]);

            backtrack(nums, index +1, n, vbUsed, path, res);

            vbUsed[i] = false;
            path.pop_back();
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() ==0)
            return res;

        int n = nums.size();
        vector<bool> vbUsed(n, false);
        vector<int> path;

        backtrack(nums, 0, n, vbUsed, path, res);

        return res;
    }
};

class SwapSolution {
    void backtrack(vector<int> &nums, int i, vector<vector<int>> &ans){
        // return condition
        // 到最后再入 res （不重复）
        if (i == nums.size() - 1){
            ans.push_back(nums);

            return;
        }

        for (int j = i; j < nums.size(); ++j) {
            std::swap(nums[j], nums[i]);

            backtrack(nums, i+1, ans);

            std::swap(nums[j], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(nums, 0, ans);

        return ans;
    }
};

int main(){
    vector<int> nums = {1, 2, 3 ,4 ,5};
    Solution solver;
    solver.permute(nums);

    return 0;
}
