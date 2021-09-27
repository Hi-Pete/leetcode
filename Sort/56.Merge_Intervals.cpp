// 56. 合并区间
// 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi]
// 请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间
//

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(),
                  [] (const vector<int> &a, const vector<int> &b) -> bool { return a[0] < b[0] ; });

        vector<vector<int>> res;

        for (auto curr : intervals) {
            if (res.empty() || curr[0] > res.back()[1])
                res.push_back(curr);
            else
                res.back()[1] = std::max(res.back()[1], curr[1]);
        }

        return res;
    }
};

int main() {
    vector<vector<int>> nums;
    nums.push_back({1, 4});
    nums.push_back({0, 2});
    nums.push_back({3, 15});
    // nums.push_back({15, 18});

    Solution solver;
    vector<vector<int>> res = solver.merge(nums);
}