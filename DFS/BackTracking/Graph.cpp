//
// Created by hipete on 21-3-15.
//

#include <vector>
#include <map>

using std::vector;
using std::map;

class Solution {
    vector <vector<int>> graph;
    vector<bool> visited;

public:
    void DFS(vector <vector<int>> &graph, int i) {
        for (const int &node : graph[i])
            if (visited[node] == 0)
                DFS(graph, node);

    }

    void travel_DFS(vector <vector<int>> &graph) {
        this->visited = vector<bool>(graph.size(), false);

        for (int i = 0; i < graph.size(); ++i)
            DFS(graph, i);
    }
};