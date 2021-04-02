// 129. 求根节点到叶节点数字之和
// 给你一个二叉树的根节点 root ，树中每个节点都存放有一个 0 到 9 之间的数字
// 每条从根节点到叶节点的路径都代表一个数字：
//      例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123
// 计算从根节点到叶节点生成的 所有数字之和
// 叶节点 是指没有子节点的节点
//

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int dfs(TreeNode* node, int cusum){
        if (!node)
            return 0;

        cusum = cusum*10 + node->val;

        if (!node->left && !node->right)
            return cusum;

        return dfs(node->left, cusum) +
               dfs(node->right, cusum);
    }

  public:
    int sumNumbers(TreeNode* root) {
        if (!root)
            return 0;

        return dfs(root, 0);
    }
};