// 105. 从前序与中序遍历序列构造二叉树
// 根据一棵树的前序遍历与中序遍历构造二叉树
// 注意: 你可以假设树中没有重复的元素
//

#include <vector>

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
    TreeNode* build(std::vector<int>& preorder, int prbgn, int prend,
                    std::vector<int>& inorder, int inbgn, int inend){
        if (prbgn>prend)
            return nullptr;

        int rootVal = preorder[prbgn];

        int index;
        for (int i = inbgn; i <= inend; i++)
            if (inorder[i]==rootVal){
                index = i;
                break;
            }
        int left_lth = index - inbgn;

        TreeNode* node = new TreeNode(rootVal);
        node->left = build(preorder, prbgn+1, prbgn+left_lth,
                           inorder, inbgn, index-1);
        node->right = build(preorder, prbgn+left_lth+1, prend,
                            inorder, index+1, inend);

        return node;
    }

    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        return build(preorder, 0, preorder.size()-1,
                     inorder, 0, inorder.size()-1);
    }
};