// 1136. 平行课程
// 已知有 N 门课程，它们以 1 到 N 进行编号
// 给你一份课程关系表 relations[i] = [X, Y]
// 用以表示课程 X 和课程 Y 之间的先修关系： 课程 X 必须在课程 Y 之前修完
// 假设在一个学期里，你可以学习任何数量的课程，但前提是你已经学习了将要学习的这些课程的所有先修课程
// 请你返回学完全部课程所需的最少学期数
// 如果没有办法做到学完全部这些课程的话，就返回 -1
//

#include <vector>
#include <set>
#include <deque>

using std::vector;
using std::set;
using std::deque;

class Solution {
public:
    // 拓扑排序
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        // 邻接表
        vector<vector<int>> adj(n+1, vector<int>());

        // 统计入度
        vector<int> inDegree(n+1);
        for (vector<int> rel : relations) {
            inDegree[rel[1]]++;
            adj[rel[0]].push_back(rel[1]);
        }

        deque<int> queue_;
        for (int i = 1; i <= n ; ++i)
            if (inDegree[i] == 0)       queue_.push_back(i);

        int step = 0;
        while (!queue_.empty()){
            int nodeN = queue_.size();
            for (int i = 0; i < nodeN; ++i) {
                int node = queue_.front();
                queue_.pop_front();

                for (const int &nb : adj[node]){
                    inDegree[nb]--;
                    if (inDegree[nb] == 0)
                        queue_.push_back(nb);
                }
            }

            step++;
        }

        for (int j = 1; j <= n; ++j)
            if (inDegree[j] > 0)    return -1;

        return  step;
    }
};