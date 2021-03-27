// 剑指 Offer 33. 二叉搜索树的后序遍历序列
// 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果
// 如果是则返回 true，否则返回 false
// 假设输入的数组的任意两个数字都互不相同
//

#include <vector>

using std::vector;

class Solution {
    bool dfs(vector<int>& postorder, int bgn, int end){
        if(bgn >= end)
            return true;

        int rootVal = postorder[end];

        int lengthL = 0;
        while (lengthL < end - bgn &&
               postorder[bgn + lengthL] <= rootVal)
            lengthL++;

        for (int i = bgn + lengthL; i < end; ++i)
            if (postorder[i] < rootVal)
                return false;

        return dfs(postorder, bgn, bgn + lengthL-1) &&
               dfs(postorder, bgn + lengthL, end-1);

    }

public:
    bool verifyPostorder(vector<int>& postorder) {
        return dfs(postorder, 0, postorder.size()-1);
    }
};

int main(){
    vector<int> nums = {1, 2, 5, 10, 6, 9, 4, 3};

    Solution solve;
    solve.verifyPostorder(nums);

    return 0;
}