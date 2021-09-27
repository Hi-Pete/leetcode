// 215. 数组中的第K个最大元素
// 在未排序的数组中找到第 k 个最大的元素
// 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素
//

#include <vector>

using std::vector;

class Solution {
    int quickSelect(vector<int> &nums, int bgn, int end, int k){
        int pivot = bgn;

        for (int i = bgn; i < end; ++i) {
            if(nums[i] <= nums[end])
                std::swap(nums[pivot++], nums[i]);
        }
        std::swap(nums[pivot], nums[end]);

        int count = end - pivot + 1;

        if(count == k)
            return nums[pivot];
        if(count > k)
            return quickSelect(nums, pivot + 1, end, k);
        return quickSelect(nums, bgn, pivot - 1, k - count);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() -1, k);
    }
};