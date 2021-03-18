// 990. 等式方程的可满足性
// 给定一个由表示变量之间关系的字符串方程组成的数组
// 每个字符串方程 equations[i] 的长度为 4，并采用两种不同的形式之一：
// "a==b" 或 "a!=b"
// 在这里，a 和 b 是小写字母（不一定不同），表示单字母变量名
// 只有当可以将整数分配给变量名，以便满足所有给定的方程时才返回 true，否则返回 false。 
//

#include <string>
#include <vector>
#include "Union-Find.cpp"

using std::string;
using std::vector;

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UF uf(26);
        for(const string &eq : equations)
            if (eq[1] == '=')
                uf.connect(eq[0]-'a', eq[3]-'a');

        for(const string &eq : equations)
            if (eq[1] == '!')
                if (uf.isConnected(eq[0]-'a', eq[3]-'a'))
                    return false;



        return true;
    }
};