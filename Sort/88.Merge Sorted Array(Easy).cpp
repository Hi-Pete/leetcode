// 88. 合并两个有序数组
// 给你两个有序整数数组 nums1 和 nums2，
// 请将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组
//

#include <vector>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    int pos = m-- + n-- - 1;    // 定位输出数组末尾的指针
    while (m >= 0 && n >= 0)    // 将 nums1[m] 和 nums2[n] 中较大者放进 nums1 数组尾部并将遍历指针移到下一个
        nums1[pos--] = nums1[m] > nums2[n]? nums1[m--]: nums2[n--];

    while (n >= 0)      // 若原 nums1 数组遍历完，直接将剩下的 nums2 数组成员放进 nums1 数组
        nums1[pos--] = nums2[n--];
}

