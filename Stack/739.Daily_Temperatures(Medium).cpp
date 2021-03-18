// 请根据每日 气温 列表，重新生成一个列表
// 对应位置的输出为：要想观测到更高的气温，至少需要等待的天数
// 如果气温在这之后都不会升高，请在该位置用 0 来代替
// 例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]
// 输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]
// 提示：气温 列表长度的范围是 [1, 30000]，每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数
//

#include <vector>
#include <stack>

class Solution {
public:
    /****************************************************************************************
    /* Leetcode 101
    /* 我们可以维护一个单调递减的栈来表示每天的温度
    /* 为了方便计算天数差, 我们这里存放位置(即日期)而非温度本身
    /* 从左向右遍历温度数组
    /* 对于每个日期 p, 如果 p 的温度比栈顶存储位置 q 的温度高,则我们取出 q,并记录 q 需要等待的天数为 p − q
    /* 重复这一过程, 直到 p 的温度小于等于栈顶存储位置的温度(或空栈)时, 将 p 插入栈顶, 然后考虑下一天
    /* 在这个过程中, 栈内数组永远保持单调递减, 避免了使用排序进行比较
    /* 最后若栈内剩余一些日期,则说明它们之后都没有出现更暖和的日期
    /*****************************************************************************************/
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
            std::vector<int> ret(temperatures.size());  // 必须这里先指定大小初始化，以供后续下标操作
            std::stack<int> temp;
            for(int i = 0; i < temperatures.size(); i++){
                while (!temp.empty()){
                    if(temperatures[i] <= temperatures[temp.top()])
                        break;

                    ret[temp.top()] = i - temp.top();
                    temp.pop();
                }
                temp.push(i);   // 入栈的是下标，方便计算天数
            }
            return ret;
        }
    }
};