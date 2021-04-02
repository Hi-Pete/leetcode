//
// Created by hipete on 21-3-29.
//

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
    bool backtrack(vector<int> &nums, vector<bool> &visited, int n,
                   int level, int edge, int begin, int sumNow) {
        if (level == 4)
            return true;

        if (sumNow == edge)
            return backtrack(nums, visited, n, level +1, edge, 0, 0);

        for (int i = begin; i < n; ++i) {
            if(sumNow + nums[i] > edge)
                continue;

            if(!visited[i]) {
                visited[i] = true;

                if(backtrack(nums, visited, n, level, edge, i+1, sumNow + nums[i]))
                    return true;

                visited[i] = false;

                // 长度相等的边都可以跳过 (???)
                while (i + 1 < n && nums[i] == nums[i+1])
                    i++;

            }
        }

        return false;
    }
public:
    bool makesquare(vector<int>& nums) {
        if(nums.empty())
            return false;

        int n = nums.size();

        int sum = 0;
        for (const int num : nums)
            sum += num;

        if (sum % 4 != 0)
            return false;

        int edge = sum/4;
        vector<bool> visited(n);

        std::sort(nums.begin(), nums.end(), std::greater_equal<int>());

        return backtrack(nums, visited, n, 0, edge, 0, 0);
    }
};

int main() {
    vector<int> nums = {6, 2, 4, 3, 1, 5, 2};

    std::sort(nums.begin(), nums.end(), std::greater<int>());

    for(const int num : nums)
        printf("%d \n", num);

    return 0;

}