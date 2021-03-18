// 304. 二维区域和检索 - 矩阵不可变
// 给定一个二维矩阵，计算其子矩形范围内元素的总和
// 该子矩阵的左上角为 (row1, col1)
// 右下角为 (row2, col2)
//

#include <vector>

using std::vector;

// 把前缀和思想拓展到二维, 即积分图(image integral)
// 先建立一个 intergral 矩阵
// intergral[i][j] 表示以位置 (0, 0) 为左上角 位置 (i+1, j+1) 为右下角的长方形中所有数字的和
// 用动态规划来计算 integral 矩阵:
//      intergral[i][j] = matrix[i-1][j-1] + integral[i-1][j] + integral[i][j-1] - integral[i-1][j-1]
class NumMatrix {
    vector<vector<int>> integral;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() && matrix[0].size()) {
            unsigned long m = matrix.size(), n = matrix[0].size();
            integral = vector<vector<int>>(m+1, vector<int>(n+1, 0));

            for (int i = 1; i < m+1; ++i)
                for (int j = 1; j < n+1; ++j)
                    integral[i][j] = matrix[i-1][j-1] +
                                     integral[i][j-1] + integral[i-1][j]
                                     - integral[i-1][j-1];
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {

        return integral[row2 + 1][col2 + 1] - integral[row2 + 1][col1] - integral[row1][col2 + 1]
                + integral[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */