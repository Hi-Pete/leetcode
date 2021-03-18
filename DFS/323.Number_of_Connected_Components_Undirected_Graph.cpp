// 323. 无向图中连通分量的数目
// 给定编号从 0 到 n-1 的 n 个节点和一个无向边列表（每条边都是一对节点）
// 请编写一个函数来计算无向图中连通分量的数目
//

#include <vector>

using std::vector;

class Solution {
    void dfs(int i , vector<vector<int>> &adj, vector<bool> &visited){
        visited[i] = true;

        for (const int &node : adj[i]){
            if (!visited[node])
                dfs(node, adj, visited);

        }

    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // 构建邻接表
        vector<vector<int>> adj(n);

        for(const vector<int> edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int count = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (!visited[i]){
                count++;
                dfs(i, adj, visited);
            }
        }

        return count;
    }
};