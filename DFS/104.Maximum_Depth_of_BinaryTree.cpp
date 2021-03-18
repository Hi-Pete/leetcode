// 104. 二叉树的最大深度
// 给定一个二叉树，找出其最大深度
// 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数
// 叶子节点是指没有子节点的节点。
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
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;

        int leftN = maxDepth(root->left);
        int rightN = maxDepth(root->right);

        // 取最大值时不用判断是否存在
        return std::max(leftN, rightN) + 1;
    }
};