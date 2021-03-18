#include <vector>

using std::vector;

class Solution {
    int getMax(vector<int> &piles){
        int max = 0;
        for(const int &pile : piles)
            max = std::max(max, pile);

        return max;
    }

    int timeof(int pile, int speed){
        return pile/speed + ( pile % speed > 0 ? 1 : 0);
    }

    bool canEat(vector<int> &piles, int speed, int H){
        int nHours = 0;
        for(const int &pile : piles)
            nHours += timeof(pile, speed);

        return nHours <= H;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = getMax(piles);

        while (left <= right){
            int mid = left + (right - left)/2;
            if (canEat(piles, mid, h))
                right = mid - 1;
            else
                left = mid + 1;
        }

        return left;
    }
};

int main(){
    vector<int> nums = {3, 6 ,7 ,11};

    Solution solve;
    solve.minEatingSpeed(nums, 8);

    return 0;
}
