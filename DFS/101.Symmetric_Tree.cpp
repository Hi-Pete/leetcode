// 101. 对称二叉树
// 给定一个二叉树，检查它是否是镜像对称的
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
public:
    // 1)如果两个子树都为空指针, 则它们对称
    // 2)如果两个子树只有一个为空指针, 则它们不对称
    // 3)如果两个子树根节点的值不相等, 则它们不对称
    // 4)根据对称要求,进行递归处理
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;

        return isSymmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode* left, TreeNode* right){
        if (!left && !right)
            return true;

        if (!left || !right)
            return false;

        if (left->val != right->val)
            return false;

        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
};