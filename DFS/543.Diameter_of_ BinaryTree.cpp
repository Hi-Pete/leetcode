// 543. 二叉树的直径
// 给定一棵二叉树，你需要计算它的直径长度
// 一棵二叉树的直径长度是任意两个结点路径长度中的最大值
// 这条路径可能穿过也可能不穿过根结点
//

#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int dfs(TreeNode* node, int &res){
        if (!node)
            return 0;

        // dfs 返回单边最长值
        int leftD = dfs(node->left, res);
        int rightD = dfs(node->right, res);

        // 用当前节点两侧最大单边最大值更新最大直径
        // 注意直径指的是两个节点中间边的数目
        res = std::max(leftD + rightD, res);

        // 返回经过当前节点的最长单边长度
        return std::max(leftD, rightD) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        dfs(root, res);

        return res;
    }
};