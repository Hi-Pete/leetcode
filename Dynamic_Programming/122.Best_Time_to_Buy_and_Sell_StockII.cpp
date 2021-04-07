// 122. 买卖股票的最佳时机 II
// 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格
// 设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）
//

#include <vector>

using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i-1])
                res += prices[i] - prices[i-1];
        }

        return res;
    }
};