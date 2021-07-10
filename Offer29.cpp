//
// Created by bigfat on 2021/4/29.
//

#include <vector>

using std::vector;

class Solution {
    void print2Vec(vector<vector<int>>& matrix, int m, int n, int bgn, vector<int> &res) {
        int endY = m - 1 - bgn;
        int endX = n - 1 - bgn;

        for (int i = bgn; i <= endX; ++i)
            res.push_back(matrix[bgn][i]);

        if(endY > bgn) {
            for (int i = bgn +1; i <= endY; ++i)
                res.push_back(matrix[i][endX]);

            if(endX > bgn) {
                for (int i = endX -1; i >= bgn ; --i)
                    res.push_back(matrix[endY][i]);

                if(endY > bgn +1) {
                    for (int i = endY -1; i > bgn; --i)
                        res.push_back(matrix[i][bgn]);
                }
            }
        }

    }

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return {};

        int m = matrix.size(), n = matrix[0].size();
        int bgn = 0;
        vector<int> res;
        res.reserve(m*n);
        while (m > bgn*2 && n > bgn*2) {
            print2Vec(matrix, m, n, bgn, res);

            bgn++;
        }

        return res;
    }
};