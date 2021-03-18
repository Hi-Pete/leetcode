// 78. 子集
// 给你一个整数数组 nums ，数组中的元素 互不相同
// 返回该数组所有可能的子集（幂集）
// 解集 不能 包含重复的子集
// 你可以按 任意顺序 返回解集
//

#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // 包括空集
        if (nums.empty())
            return {{}};

        int num = nums.back();
        nums.pop_back();

        vector<vector<int>> res = subsets(nums);

        // subset([1,2,3]) =
        //              A + [A[i].add(3) for i = 1..len(A)]
        int sz = res.size();
        for (int i = 0; i < sz; ++i) {
            res.push_back(res[i]);
            res.back().push_back(num);
        }

        return res;
    }
};

class Solution_backtrack {
    vector<vector<int>> res;

    void backtrack(vector<int> &nums, int start, vector<int> &track){
        // 将当前路径压入 res
        res.push_back(track);

        // 将 nums 中剩余的数依次压入当前路径并逐层回溯
        for (int i = start; i < nums.size(); ++i) {
            track.push_back(nums[i]);

            backtrack(nums, i+1, track);

            track.pop_back();
        }
    }

  public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> track;
        backtrack(nums, 0, track);

        return res;
    }
};


int main(){
    vector<int> nums = {1, 2, 3};

    Solution_backtrack solv = Solution_backtrack();

    solv.subsets(nums);

    return 0;
}