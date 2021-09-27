// 102. 二叉树的层序遍历
// 给你一个二叉树，请你返回其按 层序遍历 得到的节点值
// （即逐层地，从左到右访问所有节点）
//示例：
// 二叉树：[3,9,20,null,null,15,7],
//
//   3
//  / \
// 9  20
//    / \
//   15  7
// 返回其层序遍历结果：
//
// [
//  [3],
//  [9,20],
//  [15,7]
// ]
//

#include <vector>
#include <deque>

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

        std::deque<TreeNode*> nodes;
        nodes.push_back(root);
        TreeNode* pNode;
        int nextLevel = 0;
        int toBePush = 1;
        vector<int> levelNodes;

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
                ret.push_back(levelNodes);
                levelNodes.clear();

                toBePush = nextLevel;
                nextLevel = 0;
            }
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