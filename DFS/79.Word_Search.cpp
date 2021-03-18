// 79. 单词搜索
// 给定一个二维网格和一个单词，找出该单词是否存在于网格中
// 单词必须按照字母顺序，通过相邻的单元格内的字母构成
// 其中“相邻”单元格是那些水平相邻或垂直相邻的单元格
// 同一个单元格内的字母不允许被重复使用
//

#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    // 本题采用的并不是修改输出方式,而是修改访问标记
    // 在我们对任意位置进行深度优先搜索时,我们先标记当前位置为已访问,以避免重复遍历(如防止向右搜索后又向左返回)
    // 在所有的可能都搜索完成后,再回改当前位置为未访问,防止干扰其它位置搜索到当前位置
    // 使用回溯法,我们可以只对一个二维的访问矩阵进行修改,而不用把每次的搜索状态作为一个新对象传入递归函数中
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty())
            return false;

        unsigned long m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        bool ret = false;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                backtrack(i, j, board, word, ret, visited, 0);
            }
        }

        // 不管有没有找到，都会将矩阵全部遍历，似乎有些耗时
        return ret;
    }

    void backtrack(int i, int j,
                   vector<vector<char>>& board, string& word,
                   bool& ret, vector<vector<bool>> visited, int pos) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return;

        if (visited[i][j] || board[i][j] != word[pos] || ret)
            return;

        if (pos == word.size() - 1){
            ret = true;
            return;
        }

        // 修改状态
        visited[i][j] = true;

        // 4 个方向递归遍历
        backtrack(i+1, j, board, word, ret, visited, pos+1);
        backtrack(i-1, j, board, word, ret, visited, pos+1);
        backtrack(i, j+1, board, word, ret, visited, pos+1);
        backtrack(i, j-1, board, word, ret, visited, pos+1);

        // 回溯
        visited[i][j] = false;
    }
};

class Solution_2{
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool backtrack(int i, int j,
                   vector<vector<char>>& board, string &word, int pos,
                   vector<vector<bool>> visited) {
        // return case 1
        if(pos == word.size() - 1)
            return board[i][j]==word[pos];

        if (board[i][j]==word[pos]){
            visited[i][j] = true;

            for (const auto dir : dirs){
                int X = i + dir[0];
                int Y = j + dir[1];

                if (X>=0 && Y>=0 && X<board.size() && Y<board[0].size() && !visited[X][Y])
                    if (backtrack(X, Y, board, word, pos+1, visited))
                        return true;

            }

            visited[i][j] = false;
        }

        // return case 2
        return false;
    }

  public:
    bool exist(vector<vector<char>>& board, string word){
        if (board.empty())
            return false;

        unsigned long m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (backtrack(i, j, board, word, 0, visited))
                    return true;
            }
        }

        return false;
    }
};

class Solution_offer{
    bool exist(vector<vector<char>>& board, string word){

    }

};