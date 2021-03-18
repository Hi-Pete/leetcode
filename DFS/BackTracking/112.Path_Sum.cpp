// 112. 路径总和
// 给你二叉树的根节点 root 和一个表示目标和的整数 targetSum
// 判断该树中是否存在 根节点到叶子节点 的路径
// 这条路径上所有节点值相加等于目标和 targetSum
// 叶子节点 是指没有子节点的节点
//

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
    bool backtrack(TreeNode* node, int &curSum, int &target){
        curSum += node->val;

        bool isLeaf = (!node->left && !node->right);
        if(curSum == target && isLeaf)
            return true;

        if(node->left)
            if(backtrack(node->left, curSum, target)) return true;
        if(node->right)
            if(backtrack(node->right, curSum, target)) return true;

        curSum -= node->val;

        return false;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum){
        if(!root)
            return false;

        int curSum = 0;

        return  backtrack(root, curSum, targetSum);
    }
};

int main(){
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node7= new TreeNode(7);
    TreeNode* node13 = new TreeNode(13);

    TreeNode* node11 = new TreeNode(11, node7, node2);
    TreeNode* node4_3 = new TreeNode(4, nullptr, node1);
    TreeNode* node4_2 = new TreeNode(4, node11, nullptr);
    TreeNode* node8 = new TreeNode(8, node13, node4_3);
    TreeNode* node5 = new TreeNode(5, node4_2, node8);

    Solution solve;

    bool res = solve.hasPathSum(node5, 22);

    return 0;
}
