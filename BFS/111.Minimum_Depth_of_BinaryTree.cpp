// 111. 二叉树的最小深度
// 给定一个二叉树，找出其最小深度
// 最小深度是从根节点到最近叶子节点的最短路径上的节点数量
// 说明：叶子节点是指没有子节点的节点
//

#include <algorithm>
#include <queue>

using std::queue;

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
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;

        int leftN = minDepth(root->left);
        int rightN = minDepth(root->right);

        // 遇到左右子树都有的时候才比较
        return (leftN==0 || rightN==0) ? leftN + rightN + 1 : std::min(leftN, rightN) + 1;
    }
};

// 二叉树层次遍历非递归实现
class Solution_BFS {
  public:
    int minDepth(TreeNode* root){
        if (!root)
            return 0;

        queue<TreeNode*> queue;
        queue.push(root);
        int depth = 1;

        while (!queue.empty()) {
            int sz = queue.size();
            for (int i = 0; i < sz; ++i) {
                TreeNode* cur = queue.front();
                queue.pop();

                // 判断是否达到叶子结点
                if (!cur->left && !cur->right)
                    return depth;

                if (cur->left)
                    queue.push(cur->left);
                if (cur->right)
                    queue.push(cur->right);
            }
            // 增加深度
            depth++;
        }

        return depth;
    }
};