// 167. 两数之和 II - 输入有序数组
// 给定一个已按照 升序排列 的有序数组，找到两个数使得它们相加之和等于目标数
// 函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2
//
// 说明:
//      返回的下标值（index1 和 index2）不是从零开始的
//      你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素
//
#include <vector>

class Solution {
public:
    /**
     * 假设最优解的两个数的位置分别是 l 和 r
     * 我们假设在左指针在 l 左边的时候,右指针已经移动到了 r
     * 此时两个指针指向值的和小于给定值,因此左指针会一直右移直到到达 l
     * 同理,如果我们假设在右指针在 r 右边的时候,左指针已经移动到了 l;
     * 此时两个指针指向值的和大于给定值,因此右指针会一直左移直到到达 r
     * 所以双指针在任何时候都不可能处于 (l, r) 之间
     * 又因为不满足条件时指针必须移动一个,所以最终一定会收敛在 l 和 r
     */
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1, sum;
        while (l < r)
        {
            sum = numbers[l] + numbers[r];
            if (sum == target)
                break;
            if (sum < target)
                ++l;
            else --r;
        }
        return std::vector<int>{ l + 1, r + 1 };
    }
};