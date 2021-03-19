// 1011. 在 D 天内送达包裹的能力
// 传送带上的包裹必须在 D 天内从一个港口运送到另一个港口
// 传送带上的第 i 个包裹的重量为 weights[i]
// 每一天，我们都会按给出重量的顺序往传送带上装载包裹
// 我们装载的重量不会超过船的最大运载重量
// 返回能在 D 天内将传送带上的所有包裹送达的船的最低运载能力
//

#include <vector>
#include <numeric>

using std::vector;

class Solution {
    int getMax(vector<int> &weights){
        int max = 0;
        for(const int &weight : weights)
            max = std::max(max, weight);

        return max;
    }

    bool canFinish(vector<int> &weights, int D, int cap){
        int nums= 0;
        for (int i = 0; i < D; ++i) {
            // 一天的运载能力
            int capility = cap;
            while ((capility -= weights[nums]) > 0){
                nums++;     // 完成一个包裹的运载
                if (nums == weights.size()) // 立刻检查是否运载完所有包裹
                    return true;
            }
        }

        return false;
    }
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int left = getMax(weights);
        int right = std::accumulate(weights.begin(), weights.end(), 0);

        while (left <= right){
            int mid = left +(right - left)/2;
            if (canFinish(weights, D, mid)){
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return right;
    }
};

int main(){
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10};

    Solution solve;
    solve.shipWithinDays(nums, 5);

    return 0;
}