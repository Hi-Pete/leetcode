// 226. 翻转二叉树
// 翻转一棵二叉树

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* invertTree_recursively(TreeNode* root) {
        if (!root)
            return nullptr;

        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        invertTree_recursively(root->left);
        invertTree_recursively(root->right);

        return root;
    }


};