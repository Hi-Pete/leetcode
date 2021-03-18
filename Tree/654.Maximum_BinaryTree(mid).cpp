// 654. 最大二叉树
// 给定一个不含重复元素的整数数组 nums
// 一个以此数组直接递归构建的 最大二叉树 定义如下：
//      1.二叉树的根是数组 nums 中的最大元素
//      2.左子树是通过数组中 最大值左边部分 递归构造出的最大二叉树
//      3.右子树是通过数组中 最大值右边部分 递归构造出的最大二叉树
// 返回有给定数组 nums 构建的 最大二叉树
//

#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) :
                val(x), left(left), right(right) {}
};

class Solution {
  public:
    TreeNode* build(const std::vector<int>& nums_, int bgn, int end){
        if(bgn > end)
            return nullptr;
        // 找出数组中最大的元素及其下标
        int max_index, max_num = -1;
        for(int i = bgn; i<=end; i++)
            if (nums_[i] > max_num) {
                max_num =  nums_[i];
                max_index = i;
            }
        // 构造节点
        TreeNode* node = new TreeNode(max_num);

        node->left = build(nums_, bgn, max_index-1);
        node->right = build(nums_, max_index+1, end);

        return node;
    }

    TreeNode* constructMaximumBinaryTree(const std::vector<int>& nums) {
        TreeNode* root = build(nums, 0, nums.size()-1);

        return root;
    }
};