// 695. 岛屿的最大面积
// 给定一个包含了一些 0 和 1 的非空二维数组 grid
// 一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合
// 这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻
// 你可以假设 grid 的四个边缘都被 0（代表水）包围着
// 找到给定的二维数组中最大的岛屿面积
// (如果没有岛屿，则返回面积为 0 )
//

#include <vector>

using std::vector;

class Solution{
    vector<int> direction{-1, 0, 1, 0, -1};

    int dfs(int x, int y, vector<vector<int>>& grid) {
        if (grid[x][y] == 0)
            return 0;

        grid[x][y] = 0;
        int res = 1;
        for (int i = 0; i < 4; ++i) {
            int X = x + direction[i], Y = y + direction[i+1];
            if (X>=0 && X<grid.size() && Y>=0 && Y<grid[0].size())
                res += dfs(X, Y, grid);

        }
        // 无序搜索，不用回溯

        return res;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid){
        if (grid.empty() || grid[0].empty())
            return 0;
        int res = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j]==1)
                    res = std::max(res, dfs(i, j, grid));
            }
        }
        return res;
    }
};