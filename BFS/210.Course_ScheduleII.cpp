// 210. 课程表 II
// 现在你总共有 n 门课需要选，记为 0 到 n-1
// 在选修某些课程之前需要一些先修课程
// 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]
// 给定课程总量以及它们的先决条件，返回你为了学完所有课程所安排的学习顺序
// 可能会有多个正确的顺序，你只要返回一种就可以了
// 如果不可能完成所有课程，返回一个空数组
//

#include <vector>
#include <deque>

using std::vector;
using std::deque;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> inDegree(numCourses);

        for(auto pair : prerequisites){
            adj[pair[1]].push_back(pair[0]);
            inDegree[pair[0]]++;
        }

        vector<int> res;
        deque<int> queue_;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0)
                queue_.push_back(i);

        }

        while (!queue_.empty()){
            int n = queue_.size();
            for(int j = 0; j<n; j++){
                int node = queue_.front();
                res.push_back(node);
                queue_.pop_front();

                for(const int &nb : adj[node]){
                    inDegree[nb]--;
                    if (inDegree[nb]==0)
                        queue_.push_back(nb);
                }
            }
        }

        for (int i = 0; i<numCourses; i++){
            if (inDegree[i]>0)
                return vector<int>();
        }

        return res;
    }
};

