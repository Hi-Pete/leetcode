// 107. Binary Tree Level Order Traversal II
// Given the root of a binary tree,
// return the bottom-up level order traversal of its nodes' values.
// (i.e., from left to right, level by level from leaf to root).
//

#include <vector>
#include <deque>
#include <stack>

using std::stack;
using std::deque;
using std::vector;


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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root)
            return ret;

        stack<vector<int>> stack;
        deque<TreeNode*> nodes;

        TreeNode* pNode;
        int nextLevel = 0;
        int toBePush = 1;
        vector<int> levelNodes;

        nodes.push_back(root);

        while(!nodes.empty()) {
            pNode = nodes.front();
            nodes.pop_front();  // 弹出队头给 pNode

            levelNodes.push_back(pNode->val);
            --toBePush;

            if(pNode->left!=nullptr){
                nodes.push_back(pNode->left);
                ++nextLevel;
            }

            if(pNode->right!=nullptr){
                nodes.push_back(pNode->right);
                ++nextLevel;
            }

            if(toBePush==0){
                stack.push(levelNodes);
                levelNodes.clear();
                toBePush = nextLevel;
                nextLevel = 0;
            }
        }

        int n = stack.size();
        for (int i = 0; i < n; i++){
            auto vals = stack.top();
            stack.pop();
            ret.push_back(vals);
        }
        return ret;
    }
};

int main(){
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node15 = new TreeNode(15);

    TreeNode* node20 = new TreeNode(20, node15, node7);
    TreeNode* node9 = new TreeNode(9);

    TreeNode* node3 = new TreeNode(3, node9, node20);

    Solution solve;
    solve.levelOrderBottom(node3);

    return 0;
}