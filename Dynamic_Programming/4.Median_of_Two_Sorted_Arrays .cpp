// 4. 寻找两个正序数组的中位数
// 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2
// 请你找出并返回这两个正序数组的 中位数
//

#include <vector>

using std::vector;

class Solution {
    int findKth(vector<int>& nums1, int bgn1, int end1,
                vector<int>& nums2, int bgn2, int end2, int k){
        int m = end1 - bgn1 + 1;
        int n = end2 - bgn2 + 1;

        // 如果 nums1 数组的长度大于 nums2 二者交换以加快进程
        if (m > n)
            return findKth(nums2, bgn2, end2,
                           nums1, bgn1, end1, k);

        if (m == 0)
            return nums2[bgn2 + k - 1];

        if (k == 1)
            return std::min(nums1[bgn1], nums2[bgn2]);

        int n1 = std::min(k/2, m);
        int n2 = k - n1;
        int midNum1 = nums1[bgn1 + n1 - 1];
        int midNum2 = nums2[bgn2 + n2 -1];

        if (midNum1 == midNum2)
            return midNum1;
            // 剪枝
        else if (midNum1 < midNum2)
            return findKth(nums1, bgn1 + n1, end1, nums2, bgn2, bgn2 + n2 - 1, k - n1);
        else
            return findKth(nums1, bgn1, bgn1 + n1 -1, nums2, bgn2 + n2, end2, k - n2);
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int k = (m + n)/2;
        if ((m + n)%2 == 1) {
            return findKth(nums1, 0, m-1, nums2, 0, n-1, k+1);
        } else{
            return (findKth(nums1, 0, m-1, nums2, 0, n-1, k) +
                    findKth(nums1, 0, m-1, nums2, 0, n-1, k+1)) / 2.0;
        }
    }
};