// 684. 冗余连接
// 在本问题中, 树指的是一个连通且无环的无向图
// 输入一个图，该图由一个有着N个节点 (节点值不重复1, 2, ..., N) 的树及一条附加的边构成
// 附加的边的两个顶点包含在 1 到 N 中间，这条附加的边不属于树中已存在的边
// 结果图是一个以边组成的二维数组
// 每一个边的元素是一对[u, v] ，满足 u < v，表示连接顶点 u 和 v 的无向图的边
// 返回一条可以删去的边，使得结果图是一个有着N个节点的树
// 如果有多个答案，则返回二维数组中最后出现的边
// 答案边 [u, v] 应满足相同的格式 u < v
//

#include <vector>
#include <map>

using std::vector;
using std::map;

#include <numeric>

class UF {
    // 记录连通分量
    int count;
    vector<int> parent;
    vector<int> size;

public:
    UF(int n) : count(n), parent(vector<int>(n)), size(vector<int>(n, 1)){
        std::iota(parent.begin(), parent.end(), 0);
    }

    int find(int x){
        // 根节点的 parent[x] == x
        while (parent[x] != x){
            // 路径压缩
            parent[x] = parent[parent[x]];
            x = parent[x];
        }

        return x;
    }

    void connect(int p, int q){
        int rootP = find(p);
        int rootQ = find(q);

        if (rootP==rootQ)
            return;

        // 维持树的平衡
        if (size[rootP] > size[rootQ]){
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        } else{
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }

        count--;
    }

    bool isConnected(int p, int q){
        return find(p)==find(q);
    }

    int countNum(){
        return count;
    }

};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UF uf(edges.size() + 1);
        for (auto edge : edges){
            if (uf.isConnected(edge[0], edge[1]))
                return edge;

            uf.connect(edge[0], edge[1]);
        }
        return vector<int>{-1, -1};
    }
};