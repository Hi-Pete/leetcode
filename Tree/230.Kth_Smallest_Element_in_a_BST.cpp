// 230. 二叉搜索树中第K小的元素
// 给定一个二叉搜索树的根节点 root ，和一个整数 k
// 请你设计一个算法查找其中第 k 个最小元素（从 1 开始计数）
//
#include <vector>
#include <stack>

using std::vector;
using std::stack;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (!root)
            return 0;

        int rank = 0;
        stack<TreeNode *> stack;
        TreeNode *pNode = root;

        while (!stack.empty() || pNode) {
            while (pNode) {
                stack.push(pNode);
                pNode = pNode->left;
            }
            pNode = stack.top();
            stack.pop();

            rank++;
            if (rank == k)
                return pNode->val;

            pNode = pNode->right;
        }

        return 0;
    }
};