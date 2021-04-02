// 1008. 前序遍历构造二叉搜索树
// 返回与给定前序遍历 preorder 相匹配的二叉搜索树（binary search tree）的根结点
// 回想一下，二叉搜索树是二叉树的一种，其每个节点都满足以下规则
// 对于 node.left 的任何后代，值总 < node.val，而 node.right 的任何后代，值总 > node.val
// 此外，前序遍历首先显示节点 node 的值，然后遍历 node.left，接着遍历 node.right
// 题目保证，对于给定的测试用例，总能找到满足要求的二叉搜索树
//

#include <vector>

using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    TreeNode* dfs(vector<int>& preorder, int bgn, int end){
        if (bgn > end)
            return nullptr;

        int rootVal = preorder[bgn];
        int lengthL = 0;
        while (lengthL < end - bgn && preorder[bgn + lengthL + 1] <= rootVal)
            lengthL++;

        TreeNode *rootNode = new TreeNode(rootVal);
        rootNode->left = dfs(preorder, bgn + 1, bgn + lengthL);
        rootNode->right = dfs(preorder, bgn + lengthL + 1, end);
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return dfs(preorder, 0, preorder.size() -1);
    }
};

int main(){
    vector<int> nums = {8, 5, 1, 7, 10, 12};

    Solution solver;
    TreeNode* res = solver.bstFromPreorder(nums);

    return 0;
}