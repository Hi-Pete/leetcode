//
// Created by hipete on 21-3-17.
//

#include <vector>

using std::vector;

int binarySearch(vector<int> &arr, int target) {
    if (arr.size() == 0)
        return -1;

    int left = 0, right = arr.size() -1;        // 搜索区间（左闭右闭区间）
    while(left <= right){         // 搜索区间为空 时终止循环
        int mid = left + (right - left)/2;  // 防止溢出
        if(arr[mid] == target){
            return mid;
        // 缩小搜索区间（去掉 mid ）
        } else if (arr[mid] < target){
            left = mid + 1;
        } else if (arr[mid] > target){
            right = mid - 1;
        }
    }

    return -1;
}

int binarySearch_LeftBd_Open(vector<int> &arr, int target) {
    if (arr.size() == 0)
        return -1;

    int left = 0, right = arr.size();   // 搜索区间为左闭右开区间
    while (left < right) {      // 搜索区间为空时 终止循环
        int mid = left + (right - left)/2;
        if(arr[mid] == target){
            right = mid;
        } else if(arr[mid] < target){
            left = mid + 1;
        } else if(arr[mid] > target){
            right = mid;
        }
    }
    // 此时 left 和 right 相交
    // 值的含义为 arr 中小于 target 的元素数量
    if(left == arr.size())  // target 比所有元素都大
        return -1;

    return arr[left] == target ?  left : -1;
}

int binarySearch_LeftBd_Close(vector<int> &arr, int target){
    if (arr.size() == 0)
        return -1;

    int left = 0, right = arr.size() - 1;   // 搜索区间为左闭右闭区间
    while (left <= right) {      // 搜索区间为空时 终止循环
        int mid = left + (right - left)/2;
        if(arr[mid] == target){
            right = mid - 1;
        } else if(arr[mid] < target){
            left = mid + 1;
        } else if(arr[mid] > target){
            right = mid - 1;
        }
    }
    // 此时 left 和 right 相交
    // 值的含义为 arr 中小于 target 的元素数量
    if(left == arr.size())  // target 比所有元素都大
        return -1;

    return arr[left] == target ?  left : -1;
}

int binarySearch_RightBd_Open(vector<int> &arr, int target) {
    if (arr.size() == 0)
        return -1;

    int left = 0, right = arr.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            left = mid + 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else if (arr[mid] > target) {
            right = mid;
        }
    }
    if (right == 0)
        return -1;
    return arr[right-1] == target ? right-1 : -1;
}

int binarySearch_RightBd_Close(vector<int> &arr, int target){
    if (arr.size() == 0)
        return -1;

    int left = 0, right = arr.size()-1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            left = mid + 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else if (arr[mid] > target) {
            right = mid -1;
        }
    }

    if (right < 0 || arr[right] != target)
        return -1;
    return right;
}


int main(){
    vector<int> nums = {1, 2, 2, 2, 3};

    int res = binarySearch_LeftBd_Open(nums, 2);

    return 0;
}