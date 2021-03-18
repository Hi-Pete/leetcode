// 239. 滑动窗口最大值
// 给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧
// 你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位
// 返回滑动窗口中的最大值

#include <vector>
#include <deque>

class Solution {
public:
    /****************************************************************************************
    Leetcode 101
     我们可以利用双端队列进行操作:
     每当向右移动时,把窗口左端的值从队列左端剔除, 把队列右边小于窗口右端的值全部剔除
     这样双端队列的最左端永远是当前窗口内的最大值
     另外, 这道题也是单调栈的一种延申:
     该双端队列利用从左到右递减来维持大小关系
    *****************************************************************************************/
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::deque<int> index;      // 滑动窗口队列，保存元素索引
        std::vector<int> ans;       // 保存结果的向量
        for(int i = 0; i < nums.size(); ++i){    // 遍历数组 nums
            if(!index.empty() && index.front() == i - k) // 如果队列头的索引为 i-k 即为要滑出窗口的元素
                index.pop_front();     // 队列头出队列

            while(!index.empty() && nums[index.back()] <= nums[i])   // 队尾元素如果小于等于当前元素
                index.pop_back();      // 队尾元素出队列（不可能成为窗口内最大元素）

            index.push_back(i); // 当前元素进队列

            if(i >= k - 1)      // 当前元素索引大于等于 k - 1 时意味着第一个窗口已填充完毕
                ans.push_back(nums[index.front()]); // 可以开始记录结果了
        }
        return ans;
    }
};
