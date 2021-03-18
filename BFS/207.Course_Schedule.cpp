// 207. 课程表
// 你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1
// 在选修某些课程之前需要一些先修课程
// 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [a_i, b_i] ，表示如果要学习课程 ai 则 必须 先学习课程  bi
// 例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1
// 请你判断是否可能完成所有课程的学习？
// 如果可以，返回 true ；否则，返回 false
//

#include <vector>
#include <deque>

using std::vector;
using std::deque;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> inDegree(numCourses);

        for(auto pair : prerequisites){
            adj[pair[1]].push_back(pair[0]);
            inDegree[pair[0]]++;
        }

        deque<int> queue_;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0)
                queue_.push_back(i);

        }

        while (!queue_.empty()){
            int n = queue_.size();
            for(int j = 0; j<n; j++){
                int node = queue_.front();
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
                return false;
        }

        return true;
    }
};