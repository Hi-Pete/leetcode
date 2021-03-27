// 剑指 Offer 26. 树的子结构
// 输入两棵二叉树A和B，判断B是不是A的子结构
// 约定空树不是任意一个树的子结构
// B是A的子结构， 即 A中有出现和B相同的结构和节点值
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
    bool isSubTree(TreeNode* node1, TreeNode* node2){
        // base case
        if(!node2)
            return true;
        if(!node1)
            return false;

        if(node1->val != node2->val)
            return false;

        return isSubTree(node1->left, node2->left) &&
               isSubTree(node1->right, node2->right);
    }
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        bool res = false;

        if(A && B) {
            // 前序遍历找候选节点
            if (A->val == B->val)
                res = isSubTree(A, B);

            if (!res)
                res = isSubStructure(A->left, B);

            if (!res)
                res = isSubStructure(A->right, B);
        }

        return res;
    }
};