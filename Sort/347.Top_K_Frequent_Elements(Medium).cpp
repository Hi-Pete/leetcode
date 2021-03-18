// 347. 前 K 个高频元素
// 给定一个非空的整数数组，返回其中出现频率前 k 高的元素
//

#include <vector>
#include <unordered_map>
#include <queue>
#include <map>

class Solution {
public:
    /**
     * @BucketSort: 顾名思义,桶排序的意思是为每个值设立一个桶
     *              桶内记录这个值出现的次数(或其它属性)然后对桶进行排序 ( leetcode 101 )
     * @param nums
     * @param k
     * @return
     */
    std::vector<int> topKFrequent_BucketSort(std::vector<int> &nums, int k) {
        std::unordered_map<int, int> counts;    // unordered_map: map organized by a hash function
        int max_count = 0;
        for (const int &num : nums)     // 遍历输入整数数组，为每个元素建立 hash map
            // 分别保存该元素及其出现的次数，并保存所有元素最大出现次数
            max_count = std::max(max_count, ++counts[num]);
        // counts<num, num出现次数>

        std::vector<std::vector<int>> buckets(max_count + 1);// 桶排序
        // max + 1 个元素（包括 0 ）代表出现不同次数的向量
        // 确实为了桶排序多用了一个元素，不过初始化为空啦没占什么空间

        for (const auto &p : counts)                // 遍历 hash map
            buckets[p.second].push_back(p.first);   // 记录各个出现次数的元素有哪些
        // 这个数据结构（元素为向量的向量，外层向量代表 num 出现次数，内层代表num）
        // 是完成桶排序的关键
        // buckets[n]：n 为出现次数，向量内元素为出现次数为 n 的num

        std::vector<int> ret;           // ans:保存返回结果的向量
        for (int i = max_count; i >= 0 && ret.size() < k; --i)  // 从 buckets 中拿出出现次数前 k 高的元素
            for (const int &num : buckets[i])      // 从最大元素开始遍历出现次数向量
            {
                ret.push_back(num);     // 保存出现次数向量中每个元素
                if (ret.size() == k)     // 在这层循环里也要检查是否已有 k 个元素
                    break;
            }
        return ret;
    }

    /**
     * @brief: 堆排序
     * @param nums
     * @param k
     * @return
     */
    std::vector<int> topKFrequent_priority_queue(std::vector<int>& nums, int k) {
        // pair<count, val>
        using E = std::pair<int, int>;
        /**
         *  @brief  A standard container automatically sorting its contents.
         *
         *  @ingroup sequences
         *
         *  @tparam _Tp  Type of element.
         *  @tparam _Sequence  Type of underlying sequence, defaults to vector<_Tp>.
         *  @tparam _Compare  Comparison function object type, defaults to
         *                    less<_Sequence::value_type>.
        **/
        // 定义最小堆
        std::priority_queue<E, std::vector<E>, std::greater<E>> minHeap;

        std::map<int, int> counter;
        for (auto e : nums)
            ++counter[e];           // 遍历输入，统计数频

        for (auto& x : counter) {   // 堆排序 要遍历所有元素，没有桶排序快
            auto pair = std::make_pair(x.second, x.first);      // 临时变量，存储数频对

            if (minHeap.size() == k)        // 如果堆中元素到 k 个也要继续比较新元素和堆顶元素
            {
                if (pair < minHeap.top())   // 如果当前元素小于堆顶元素（比较出现次数）
                    continue;               // 继续下一 for 循环
                minHeap.pop();              // 否则弹出栈顶元素
            }           // std::move 函数，骚操作
            minHeap.push(std::move(pair));  // 并当前元素入优先队列（自动排序）
        }

        std::vector<int> ret(minHeap.size());
        while(!minHeap.empty()) {
            ret[--k] = minHeap.top().second;    // 最小堆，所以倒着往 ret 里装
            minHeap.pop();                      // 装完就弹出堆顶
        }
        return ret;
    }
};

