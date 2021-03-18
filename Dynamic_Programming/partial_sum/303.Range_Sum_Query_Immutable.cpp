// 303. 区域和检索 - 数组不可变
// 给定一个整数数组 nums，求出数组从索引 i 到 j（i ≤ j）范围内元素的总和
// 包含 i、j 两点
// 实现 NumArray 类：
//      NumArray(int[] nums) 使用数组 nums 初始化对象
//      int sumRange(int i, int j)  返回数组 nums 从索引 i 到 j（i ≤ j）范围内元素的总和
//                                  包含 i、j 两点, 也就是 sum(nums[i], nums[i + 1], ... , nums[j])
//

#include <numeric>

#include <vector>

using std::vector;

class NumArray {
    vector<int> psum;
  public:
                                // initiaizor
    NumArray(vector<int>& nums) : psum(nums.size() + 1, 0) {
                                                // 注意前缀和第一项为 0
        std::partial_sum(nums.begin(), nums.end(), psum.begin() + 1);
    }

    int sumRange(int i, int j) {
        return psum[j+1] - psum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */