//
// Created by hipete on 21-3-16.
//

#include <vector>

using std::vector;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int left = 0, right = numbers.size() - 1;

        while(numbers[left] > numbers[right] ||  right > left){
            int mid = left + (right - left)/2;
            if(numbers[mid] > numbers[left]){
                left = mid;
            }else if(numbers[mid] < numbers[left]){
                right = mid;
            } else{
                left = mid + 1;

            }
        }

        return numbers[right]>numbers[left]? numbers[left]:numbers[right];
    }
};

int main(){
    vector<int> nums = {2, 2, 2, 0, 1};

    Solution solve;
    int res = solve.minArray(nums);

    return 0;
}