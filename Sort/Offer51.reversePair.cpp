// 剑指 Offer 51. 数组中的逆序对
// 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对
// 输入一个数组，求出这个数组中的逆序对的总数
//

#include <vector>

using std::vector;

class Solution {
    vector<int> merge(vector<int> &arr1, vector<int> &arr2){
        vector<int> res(arr1.size() + arr2.size());

        int index_1 = 0;
        int index_2 = 0;
        while (index_1 < arr1.size() && index_2 < arr2.size()){
            if (arr1[index_1] <= arr2[index_2]) {
                res[index_1 + index_2] = arr1[index_1];
                index_1++;
            } else {
                res[index_1 + index_2] = arr2[index_2];
                index_2++;
            }
        }

        while (index_1 < arr1.size()){
            res[index_1 + index_2] = arr1[index_1];
            index_1++;
        }
        while (index_2 < arr2.size()){
            res[index_1 + index_2] = arr2[index_2];
            index_2++;
        }

        return res;
    }

    vector<int> mergeSortCore(vector<int> &arr, int bgn, int end){
        if (bgn == end)
            return vector<int>(1, arr[bgn]);

        int mid = (bgn + end)/2;

        vector<int> leftL = mergeSortCore(arr, bgn, mid);
        vector<int> rightN = mergeSortCore(arr, mid + 1, end);

        return merge(leftL, rightN);
    }

    void mergeSort(vector<int> &arr) {
        if(arr.size()==0)
            return;

        vector<int> res = mergeSortCore(arr, 0, arr.size()-1);

        for (int i = 0; i < arr.size(); ++i)
            arr[i] = res[i];

    }

    int reversePairsCore(vector<int> &data, vector<int> &res, int bgn, int end) {
        if (bgn==end){
            res[bgn] = data[bgn];
            return 0;
        }

        int mid = (end - bgn)/2;

        int left = reversePairsCore(data, res, bgn, bgn + mid);
        int right = reversePairsCore(data, res, bgn + mid + 1, end);

        int leftIdx = bgn + mid;
        int rightIdx = end;
        int resIdx = end;

        int count = 0;
        while (leftIdx >= bgn && rightIdx >= bgn + mid + 1){
            if(data[leftIdx] > data[rightIdx])
            {
                res[resIdx--] = data[leftIdx--];
                count += rightIdx - (bgn+mid);
            } else
                res[resIdx--] = data[rightIdx--];
        }

        for (; leftIdx >= bgn ; leftIdx--)
            res[resIdx--] = data[leftIdx];
        for (; rightIdx >= bgn + mid + 1; rightIdx--)
            res[resIdx--] = data[rightIdx];

        return left + right + count;

    }
public:
    int reversePairs(vector<int>& nums) {
        if(nums.empty())
            return 0;

        vector<int> res(nums.size());

        return reversePairsCore(nums, res, 0, nums.size() - 1);
    }
};

int main() {
    vector<int> nums = {7, 5, 6, 4};

    Solution solver;
    int res = solver.reversePairs(nums);

    return 0;
}