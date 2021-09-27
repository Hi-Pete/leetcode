// 113. 路径总和 II
// 给你二叉树的根节点 root 和一个整数目标和 targetSum
// 找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径
// 叶子节点 是指没有子节点的节点
//

#include <vector>

using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    void backtrack(TreeNode* node,
                   int curSum, int target,
                   vector<int> &path,
                   vector<vector<int>> &res) {
        path.push_back(node->val);
        curSum += node->val;

        bool isLeaf = (!node->left && !node->right);
        if(curSum == target && isLeaf)
           res.push_back(path);

        if(node->left)
            backtrack(node->left, curSum, target, path, res);
        if(node->right)
            backtrack(node->right, curSum, target, path, res);

        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        if(!root)
            return res;

        int curSum = 0;
        vector<int> path;
        backtrack(root, curSum, targetSum, path, res);

        return res;
    }
};