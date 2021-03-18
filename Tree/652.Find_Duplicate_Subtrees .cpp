// 652. Find Duplicate Subtrees
// 给定一棵二叉树，返回所有重复的子树
// 对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可
// 两棵树重复是指它们具有相同的结构以及相同的结点值
//

#include <vector>
#include <set>
#include <string>

using std::vector;
using std::multiset;
using std::string;

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
    multiset<string> count_set;
    vector<TreeNode*> ret;

    string traverse(TreeNode* root) {
        if (root == nullptr)
            return "#";

        string left = traverse(root->left);
        string right = traverse(root->right);

        string subTree = left + "," + right + "," + std::to_string(root->val);
        count_set.insert(subTree);

        if (count_set.count(subTree) == 2)
            ret.push_back(root);

        return subTree;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        traverse(root);
        return ret;
    }
};