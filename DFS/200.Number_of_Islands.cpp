// 200. 岛屿数量
// 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量
// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成
// 此外，你可以假设该网格的四条边均被水包围
//

#include <vector>

using std::vector;

class Solution {
    vector<int> direction{-1, 0, 1, 0, -1};

    void dfs(int x, int y, vector<vector<char>>& grid) {
        if (grid[x][y] == '0')
            return;

        grid[x][y] = '0';
        for (int i = 0; i < 4; ++i) {
            int X = x + direction[i], Y = y + direction[i+1];
            if (X>=0 && X<grid.size() && Y>=0 && Y<grid[0].size())
                dfs(X, Y, grid);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid){
        if (grid.empty() || grid[0].empty())
            return 0;

        int res = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); ++j)
                if (grid[i][j]=='1'){
                    ++res;
                    dfs(i, j, grid);
                }

        return res;
    }
};