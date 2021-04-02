// 417. 太平洋大西洋水流问题
// 给定一个 m x n 的非负整数矩阵来表示一片大陆上各个单元格的高度
// “太平洋”处于大陆的左边界和上边界，而“大西洋”处于大陆的右边界和下边界
// 规定水流只能按照上、下、左、右四个方向流动，且只能从高到低或者在同等高度上流动
// 请找出那些水流既可以流动到“太平洋”，又能流动到“大西洋”的陆地单元的坐标
//

#include <vector>

using std::vector;

class Solution {
    vector<int> direction{-1, 0, 1, 0, -1};

    void dfs(const vector<vector<int>> &heights,
             vector<vector<bool>> &canGo, int row, int col)
    {
        if(canGo[row][col])
            return;

        canGo[row][col] = true;

        int x, y;
        for(int i = 0; i < 4; i++){
            x = row + direction[i];
            y = col + direction[i+1];

            if (x >= 0 && x < heights.size() &&
                y >= 0 && y < heights[0].size() &&
                heights[x][y] >= heights[row][col])

                dfs(heights, canGo, x, y);

        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if(heights.empty() || heights[0].empty())
            return {};

        vector<vector<int>> res;
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> canGoPac(m, vector<bool>(n, false));
        vector<vector<bool>> canGoAtl(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            dfs(heights, canGoPac, i, 0);
            dfs(heights, canGoAtl, i, n-1);
        }

        for (int j = 0; j < n; ++j) {
            dfs(heights, canGoPac, 0, j);
            dfs(heights, canGoAtl, m-1, j);
        }

        for (int rw = 0; rw < m; ++rw)
            for (int cl = 0; cl < n; ++cl)
                if(canGoAtl[rw][cl] && canGoPac[rw][cl])
                    res.push_back({rw, cl});

        return res;
    }
};
