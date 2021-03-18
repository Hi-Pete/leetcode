// 110. 平衡二叉树
// 给定一个二叉树，判断它是否是高度平衡的二叉树
// 本题中，一棵高度平衡二叉树定义为：
//      一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1
//

#include <cmath>
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
    // 先处理子树的深度再进行较
    // 如果我们在处理子树时发现其已经不平衡了, 则可以返回一个-1,使得所有其长辈节点可以避免多余的判断
    // 后序遍历
    bool isBalance(TreeNode* node, int &depth){
        if (!node){
            depth = 0;

            return true;
        }

        int leftD, rightD;
        if (isBalance(node->left, leftD) && isBalance(node->right, rightD)) {
            if (std::abs(leftD - rightD) <= 1){
                //  向上传递深度
                depth = 1 + std::max(leftD, rightD);

                return true;
            }
        }

        return false;
    }
public:
    bool isBalanced(TreeNode* root) {
        int depth = 0;
        return isBalance(root, depth);
    }
};