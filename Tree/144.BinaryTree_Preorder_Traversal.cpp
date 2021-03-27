// 144. 二叉树的前序遍历
// Given the root of a binary tree,
// return the preorder traversal of its nodes' values
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (!root)
            return ret;
        stack<TreeNode*> stack;
        TreeNode* pNode = root;

        while(!stack.empty() || pNode){
            while (pNode){
                ret.push_back(pNode->val);
                stack.push(pNode);
                pNode = pNode->left;
            }
            pNode = stack.top();
            stack.pop();

            pNode = pNode->right;
        }

        return ret;
    }
};