// 226. 翻转二叉树
// 翻转一棵二叉树

#include <stack>

using std::stack;

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

        // 前序遍历
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        invertTree_recursively(root->left);
        invertTree_recursively(root->right);

        return root;
    }

    TreeNode* mirrorTree(TreeNode* root) {
        if(root == nullptr) return nullptr;
        stack<TreeNode*> stack;
        stack.push(root);
        // 层次遍历
        while (!stack.empty())
        {
            TreeNode* node = stack.top();
            stack.pop();

            if (node->left)
                stack.push(node->left);
            if (node->right)
                stack.push(node->right);

            TreeNode* tmp = node->left;
            node->left = node->right;
            node->right = tmp;
        }
        return root;
    }
};