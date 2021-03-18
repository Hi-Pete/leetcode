//
// Created by hipete on 21-3-16.
//

#include <vector>

using std::vector;

class UF{
    // 记录连通分量
    int count;
    vector<int> parent;
    vector<int> size;

public:
    UF(int n) : count(n), parent(vector<int>(n)), size(vector<int>(n)){
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            size[i] = 1;
        }
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