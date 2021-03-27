// 94. 二叉树的中序遍历
// 给定一个二叉树的根节点 root
// 返回它的 中序 遍历
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (!root)
            return ret;
        stack<TreeNode*> stack;
        TreeNode* pNode = root;

        while(!stack.empty() || pNode){
            while (pNode){
                stack.push(pNode);
                pNode = pNode->left;
            }
            pNode = stack.top();
            stack.pop();
            ret.push_back(pNode->val);

            pNode = pNode->right;
        }

        return ret;
    }
};