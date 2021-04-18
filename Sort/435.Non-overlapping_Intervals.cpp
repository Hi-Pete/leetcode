// 435. 无重叠区间
// 给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠
//

#include <vector>
#include <algorithm>

using std::vector;

class HardSolution {
    int dp(int prev, int cur, vector<vector<int>> &intervals){
        if (cur == intervals.size())
            return 0;

        int taken = INT16_MAX, notTaken;
        if (prev == -1 || intervals[prev][1] <= intervals[cur][0])
            taken = dp(cur, cur +1, intervals);

        notTaken = dp(prev, cur +1, intervals) +1;

        return std::min(taken, notTaken);
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(),
                  [] (const vector<int> &a, const vector<int> &b) -> bool { return a[0] < b[0] ; });

        return dp(-1, 0, intervals);
    }
};

class GreedySolution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0)
            return 0;

        std::sort(intervals.begin(), intervals.end(),
                  [] (const vector<int> &a, const vector<int> &b) -> bool { return a[0] < b[0] ; });

        int end = intervals[0][1];
        int count = 0;
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i][0] < end){
                end = std::min(end, intervals[i][1]);
                count++;
            } else
                end = intervals[i][1];
        }

        return count;
    }
};

int main() {
    vector<vector<int>> nums;
    nums.push_back({1, 2});
    nums.push_back({2, 3});
    nums.push_back({3, 4});
    nums.push_back({1, 3});

    Solution solver;
    int res = solver.eraseOverlapIntervals(nums);
}