// 785. 判断二分图
// 给定一个无向图graph，当这个图为二分图时返回true
// 如果我们能将一个图的节点集合分割成两个独立的子集 A 和 B
// 并使图中的每一条边的两个节点一个来自A集合，一个来自B集合
// 我们就将这个图称为二分图
// graph将会以邻接表方式给出，graph[i]表示图中与节点i相连的所有节点
// 每个节点都是一个在 0 到 graph.length-1 之间的整数
// 这图中没有自环和平行边：
//      graph[i] 中不存在 i，并且 graph[i] 中没有重复的值
//

#include <vector>
#include <queue>

using std::vector;
using std::queue;

class Solution {
    vector<bool> visited;
    vector<bool> color;
public:
    bool dfs(vector<vector<int>>& graph, int i, bool colr){
        visited[i] = true;
        this->color[i] = colr;

        for(auto neighbor : graph[i]){
            if(!visited[neighbor]) {
                if (!dfs(graph, neighbor, !colr))
                    return false;
            } else if(color[neighbor] == color[i]){
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        this->color = vector<bool> (graph.size());
        this->visited = vector<bool> (graph.size(), false);

        for (int i = 0; i < graph.size(); ++i) {
            if (!visited[i])
                if(!dfs(graph, i, true))
                    return false;
        }

        return true;

    }
};


class Solution_101{
public:
    bool isBipartite(vector<vector<int>>& graph) {
        if (graph.size()==0)
            return true;

        vector<int> color(graph.size(), 0);
        queue<int> queue_;
        // BFS
        for (int i = 0; i < graph.size(); ++i) {
            if (!color[i]) {
                queue_.push(i);
                color[i] = 1;
            }

            while(!queue_.empty()) {
                int node = queue_.front();
                queue_.pop();
                for (const int &neighbor : graph[node]) {
                    if (!color[neighbor]) {
                        queue_.push(neighbor);
                        color[neighbor] = color[node] == 1 ? 2 : 1;
                    } else if (color[neighbor] == color[node]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }

};