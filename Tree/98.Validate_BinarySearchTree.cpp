// 98. 验证二叉搜索树
// 给定一个二叉树，判断其是否是一个有效的二叉搜索树
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
    bool isBST(TreeNode* root, TreeNode* min, TreeNode* max){
        // base case
        if (!root)
            return true;

        if(min && root->val <= min->val)
            return false;

        if(max && root->val >= max->val)
            return false;

        return isBST(root->left, min, root) && isBST(root->right, root, max);
    }
public:
    bool isValidBST(TreeNode* root) {
        return isBST(root, nullptr, nullptr);
    }
};