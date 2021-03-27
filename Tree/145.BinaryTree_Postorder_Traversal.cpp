// 145. 二叉树的后序遍历
// 给定一个二叉树
// 返回它的 后序 遍历
//

#include <vector>
#include <stack>

using std::vector;
using std::stack;

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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ret;
        if (!root)
            return ret;
        stack<TreeNode*> stack;
        TreeNode* pNode = root;

        TreeNode *prev = nullptr;

        while (!stack.empty() || pNode) {
            // 1.遍历到最左子节点
            while (pNode) {
                stack.push(pNode);
                pNode = pNode->left;
            }

            pNode = stack.top();
            stack.pop();
            // 存在右子树且未被访问过的话
            // 遍历右子树
            if (pNode->right && pNode->right != prev) {
                // 重复压栈以记录当前路径分叉节点
                stack.push(pNode);
                pNode = pNode->right;
            } else {
                // 后序：在 node->left 和 node->right 之后遍历
                // 注意：此时node的左右子树应均已完成访问
                ret.push_back(pNode->val);
                // 避免重复访问右子树[记录当前节点便于下一步对比]
                prev = pNode;
                // 避免重复访问左子树[设空节点]
                pNode = nullptr;
            }
        }
        return ret;
    }
};