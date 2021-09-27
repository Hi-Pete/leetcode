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
        // 记录删除的区间个数
        int count = 0;
        for (int i = 0; i < intervals.size(); ++i) {
            // 若区间有重叠
            if (intervals[i][0] < end){
                // 删除结束时间晚的区间
                end = std::min(end, intervals[i][1]);
                count++;
            } else
                end = intervals[i][1];
        }

        return count;
    }
};

class GreedySolution_endTime {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0)
            return 0;

        std::sort(intervals.begin(), intervals.end(),
                  [] (const vector<int> &a, const vector<int> &b) -> bool { return a[1] < b[1] ; });

        // 记录最多少不重叠区间
        int end = intervals[0][1];
        int count = 1;
        for (int i = 1; i < intervals.size(); ++i) {
            if (end <= intervals[i][0]) {
                end = intervals[i][1];
                count++;
            }
        }

        return intervals.size() - count;
    }
};

int main() {
    vector<vector<int>> nums;
    nums.push_back({1, 2});
    nums.push_back({2, 3});
    nums.push_back({3, 4});
    nums.push_back({1, 3});

    GreedySolution_endTime solver;
    int res = solver.eraseOverlapIntervals(nums);
}