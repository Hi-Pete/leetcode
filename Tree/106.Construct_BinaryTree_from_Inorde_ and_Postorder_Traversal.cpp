// 106. 从中序与后序遍历序列构造二叉树
// 根据一棵树的中序遍历与后序遍历构造二叉树
// 注意: 你可以假设树中没有重复的元素
//

#include <vector>

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
    TreeNode* build(vector<int>& inorder, int inbgn, int inend,
                    vector<int>& postorder, int postbgn, int postend){
        if (inbgn>inend)
            return nullptr;

        int rootval = postorder[postend];

        int index;
        for (int i=inbgn; i<=inend; i++)
            if (inorder[i] == rootval){
                index = i;
                break;
            }
        int left_length = index - inbgn;

        TreeNode* pNode = new TreeNode(rootval);
        pNode->left = build(inorder, inbgn, inbgn + left_length-1,
                            postorder, postbgn, postbgn + left_length-1);
        pNode->right = build(inorder, index + 1, inend,
                             postorder, postbgn + left_length, postend-1);
        return pNode;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, 0, inorder.size()-1,
                     postorder, 0, postorder.size()-1);
    }
};