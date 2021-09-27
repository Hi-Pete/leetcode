//
// Created by hipete on 21-3-10.
//

#include <vector>

using std::vector;

#include <cstdio>

class Sort_n2 {
public:
    // 冒泡排序有三种写法
    // 1. 一边比较一边向后两两交换，将最大值 / 最小值冒泡到最后一位
    void bubbleSort_1(vector<int> &arr){
        for (int i = 0; i < arr.size(); ++i)
            for (int j = 0; j < arr.size()-1; ++j)
                if(arr[j] > arr[j+1])
                {
                    // 先加后减的交换
                    arr[j+1] = arr[j+1] + arr[j];
                    arr[j] = arr[j+1] - arr[j];
                    arr[j+1] = arr[j+1] - arr[j];
                }
    }

    // 使用一个变量记录当前轮次的比较是否发生过交换
    // 如果没有发生交换表示已经有序，不再继续排序
    void bubbleSort_2(vector<int> &arr) {
        bool swapped = true;

        for (int i = 0; i < arr.size(); ++i) {
            // 检查上一轮比较前是否有过交换
            if (!swapped)
                break;

            // 每一轮比较前先将 swapped 置为 false
            swapped = false;
            for (int j = 0; j < arr.size() - 1; ++j) {

                if (arr[j] > arr[j+1])
                {
                    arr[j+1] = arr[j+1] + arr[j];
                    arr[j] = arr[j+1] - arr[j];
                    arr[j+1] = arr[j+1] - arr[j];

                    // 交换后将 swapped 置为 true
                    swapped = true;
                }
            }
        }
    }

    // 除了使用变量记录当前轮次是否发生交换外
    // 再使用一个变量记录上次发生交换的位置
    // 下一轮排序时到达上次交换的位置就停止比较
    void bubbleSort_3(vector<int> &arr) {
        bool swapped = true;
        int latSwapIndex = arr.size() - 1;
        int Index = -1;

        while (swapped) {
            // swapped 初始值设为 true 是为了进入排序循环
            // 进来之后立即设为 false
            swapped = false;
            for (int i = 0; i < latSwapIndex; ++i) {
                if (arr[i] > arr[i+1]){
                    arr[i+1] = arr[i+1] + arr[i];
                    arr[i] = arr[i+1] - arr[i];
                    arr[i+1] = arr[i+1] - arr[i];

                    swapped = true;
                    Index = i;
                }
            }

            // 每一轮结束更新最后迭代下标
            latSwapIndex = Index;
        }

    }

    // 选择排序的思想是：
    // 双重循环遍历数组
    // 每经过一轮比较，找到最小元素的下标，将其交换至首位
    void selectionSort(vector<int> &arr) {
        int miniIndex;

        for (int i = 0; i < arr.size() - 1; ++i) {
            miniIndex = i;
            for (int j = i+1; j < arr.size(); ++j) {
                // 比较并记录当前最小
                if (arr[j]<arr[miniIndex])
                    miniIndex = j;
            }

            // 每一轮将剩余元素中最小移到首尾
            int tmp = arr[i];
            arr[i] = arr[miniIndex];
            arr[miniIndex] = tmp;
        }
    }

    // 既然每轮遍历时找出了最小值，何不把最大值也顺便找出来呢
    // 这就是二元选择排序的思想
    void selectionSort2(vector<int> &arr) {
        int miniIndex, maxIndex;

        // i 只需要遍历一半
        for (int i = 0; i < arr.size()/2; i++) {
            miniIndex = i;
            maxIndex = i;
            for (int j = i + 1; j < arr.size() - 1 - i; ++j) {
                if (arr[j] < arr[miniIndex])
                    miniIndex = j;

                if (arr[j] > arr[maxIndex])
                    maxIndex = j;
            }
            // 如果 minIndex 和 maxIndex 都相等
            // 那么他们必定都等于 i，且后面的所有数字都与 arr[i] 相等
            // 此时已经排序完成
            if (maxIndex==miniIndex)
                break;

            int tmp = arr[i];
            arr[i] = arr[miniIndex];
            arr[miniIndex] = tmp;

            // 如果最大值的下标刚好是 i
            // 由于 arr[i] 和 arr[minIndex] 已经交换了
            // 所以这里要更新 maxIndex 的值
            if (maxIndex == i)
                maxIndex = miniIndex;

            // 将最大元素交换至末尾
            int lastIndex = arr.size() - 1 - i;
            tmp = arr[lastIndex];
            arr[lastIndex] = arr[maxIndex];
            arr[maxIndex] = tmp;
        }
    }

    void insertSort(vector<int> &arr){
        // 从第二个数开始，往前插入数字
        for (int i = 1; i < arr.size(); ++i) {
            int curNum = arr[i];
            int index = i-1;
            while (index >= 0 && curNum<arr[index]){
                arr[index+1] = arr[index];
                index--;
            }
            // 两种情况会跳出循环：
            //      1. 遇到一个小于或等于 currentNumber 的数字，跳出循环
            //          currentNumber 就坐到它后面
            //      2. 已经走到数列头部，仍然没有遇到小于或等于 currentNumber 的数字，也会跳出循环
            //          此时 j 等于 -1，currentNumber 就坐到数列头部
            arr[index + 1] = curNum;
        }
    }

    // 插入数据时，不仅可以用这种移动元素的方式，还可以使用交换元素的方式
    void insertSort_swap(vector<int> &arr) {
        for (int i = 1; i < arr.size(); ++i) {
            int cur = i;
            // 当前数字比前一个数字小，则将当前数字与前一个数字交换
            while (cur>=0 && arr[cur] < arr[cur-1]){
                int tmp = arr[cur];
                arr[cur] = arr[cur-1];
                arr[cur-1] = tmp;

                cur--;
            }
        }
    }

};

class ShellSort {
public:
    // 希尔排序
    void shellSort(vector<int> &arr) {
        // 间隔序列， 此处用的是希尔增量序列
        for (int gap = arr.size() / 2; gap > 0; gap /= 2) {
            // 分组
            for (int groupBgnIndex = 0; groupBgnIndex < gap; ++groupBgnIndex) {
                // 对每组进行插入排序
                // 从每组第二个 num 开始往前比较
                for (int curIndex = groupBgnIndex + gap; curIndex < arr.size(); curIndex += gap) {
                    // 存当前值
                    int curNum = arr[curIndex];
                    // 遍历指针
                    int index = curIndex - gap;
                    while (index >= groupBgnIndex && curNum < arr[index]) {
                        arr[index + gap] = arr[index];
                        index -= gap;
                    }

                    arr[index + gap] = curNum;
                }
            }
        }
    }

    // 对于计算机来说，它更喜欢从第 gap 个元素开始
    // 按照顺序将每个元素依次向前插入自己所在的组的方式排序
    void shellSort_prem(vector<int> &arr) {
        for (int gap = arr.size() / 2; gap > 0; gap /= 2) {
            // 从 gap 开始
            // 按照顺序将每个元素依次向前插入自己所在的组
            for (int i = gap; i < arr.size(); ++i) {
                // 存当前值, 为它找位置
                int curNum = arr[i];
                // 遍历指针
                int index = i - gap;
                while (index >= 0 && curNum < arr[index]) {
                    arr[index + gap] = arr[index];
                    index -= gap;
                }

                arr[index + gap] = curNum;
            }
        }
    }

    // Knuth 增量序列
    // D_1 = 1; D_k+1 = 3 * D_k + 1
    // 也就是 {1, 4, 13, 40, ...}
    void shellSortByKnuth(vector<int> &arr) {
        // 计算当前数组需要用到的 Knuth 序列中的最大值
        int maxKnuth = 1;
        while (maxKnuth <= arr.size() / 3)
            maxKnuth = maxKnuth * 3 + 1;

        for (int gap = maxKnuth; gap > 0; gap = (gap - 1) / 3) {
            for (int i = gap; i < arr.size(); ++i) {
                int curNums = arr[i];
                int index = i - gap;
                while (index >= 0 && curNums < arr[index]) {
                    arr[index + gap] = arr[index];
                    index -= gap;
                }

                arr[index + gap] = curNums;
            }
        }
    }
};

class HeapSort{
    void exchang(vector<int> &arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

public:
    // 堆排序
    // 将根节点的下标视为 0，则完全二叉树有如下性质：
    //      - 对于完全二叉树中的第 i 个数，它的左子节点下标：left = 2i + 1
    //      - 对于完全二叉树中的第 i 个数，它的右子节点下标：right = left + 1
    //      - 对于有 n 个元素的完全二叉树（n >2），它的最后一个非叶子结点的下标：n/2 - 1
    void maxHeapify(vector<int> &arr, int i, int heapSize) {
        int leftN = 2 * i + 1;
        int rightN = leftN + 1;

        // 将当前节点与其左右孩子比较
        // 找出最大者
        int maxN = i;
        if (leftN < heapSize && arr[leftN] > arr[maxN])
            maxN = leftN;
        if (rightN < heapSize && arr[rightN] > arr[maxN])
            maxN = rightN;

        if (maxN != i) {
            exchang(arr, maxN, i);
            // 接着为被从顶部踢下来的元素找位置
            maxHeapify(arr, maxN, heapSize);
        }
    }

    void buildMaxHeap(vector<int> &arr) {
        // 从最后一个非叶子结点开始调整最大堆
        for (int i = arr.size() / 2 - 1; i >= 0; i--)
            maxHeapify(arr, i, arr.size());

    }

    void heapSort(vector<int> &arr) {
        // 构建最大堆
        buildMaxHeap(arr);
        for (int i = arr.size() - 1; i > 0; i--) {
            exchang(arr, 0, i);
            maxHeapify(arr, 0, i);
        }
    }
};

class QuickSort {
    void exchang(vector<int> &arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
public:
    // 快速排序算法的基本思想是：
    //      - 从数组中取出一个数，称之为基数（pivot）
    //      - 遍历数组，将比基数大的数字放到它的右边，比基数小的数字放到它的左边
    //        遍历完成后，数组被分成了左右两个区域
    //      - 将左右两个区域视为两个数组，重复前两个步骤，直到排序完成
    void quickSort(vector<int> &arr) {
        quickSortCore(arr, 0, arr.size() - 1);
    }

//    void quickSort(vector<int> &arr, int bgn, int end){
//        // 将数组分区，并获得中间值的下标
//        int mid = partition(arr, bgn, end);
//
//        // 当数字至少为 2 个时，才执行这个区域的快速排序
//        if (mid > bgn+1)
//            quickSort(arr, bgn, mid - 1);
//        if (mid < end - 1)
//            quickSort(arr, mid + 1, end);
//    }

    // 简化递归条件
    void quickSortCore(vector<int> &arr, int bgn, int end) {
        // 若待划分区域中数字数小于 2
        // 不用排序
        if (bgn >= end)
            return;

        int mid = partition(arr, bgn, end);

        quickSortCore(arr, bgn, mid - 1);
        quickSortCore(arr, mid + 1, end);

    }

    // 将 arr 从 start 到 end 这一区间的值分成两个区域
    // 左边区域的每个数都比基数小，右边区域的每个数都比基数大
    // 然后返回中间值的下标
    int partition(vector<int> &arr, int bgn, int end) {
        // 取第一个数为基数
        int pivot = arr[bgn];
        int left = bgn + 1;
        int right = end;

        // 从 left 开始
        // 遇到比基数大的数，就交换到数组最后，并将 right -1
        // 直到 left 和 right 相遇
        // 此时数组就被分成了左右两个区域
        // 再将基数和中间的数交换，返回中间值的下标即可
        while (left < right) {
            // 找到第一个大于基数的位置
            while (left < right && arr[left] <= pivot)
                left++;

            if (left != right) {
                exchang(arr, left, right);
                right--;
            }
        }

        if (arr[right] > pivot)
            right--;
        if (right != bgn)
            exchang(arr, bgn, right);

        return right;
    }

    int partition_two_pointers(vector<int> &arr, int bgn, int end) {
        int pivot = arr[bgn];
        int left = bgn + 1;
        int right = end;

        while (left < right) {
            while (left < right && arr[left] <= pivot)
                left++;

            while (left < right && arr[right] >= pivot)
                right--;

            if (left < right) {
                exchang(arr, left,  right);
                left++;
                right--;
            }
        }

        if (arr[right] > pivot)
            right--;

        exchang(arr, bgn, right);

        return right;
    }
};

class MergeSort {
    vector<int> merge(vector<int> &arr1, vector<int> &arr2){
        vector<int> res(arr1.size() + arr2.size());

        int index_1 = 0;
        int index_2 = 0;
        while (index_1 < arr1.size() && index_2 < arr2.size()){
            if (arr1[index_1] <= arr2[index_2]){
                res[index_1 + index_2] = arr1[index_1];
                index_1++;
            } else{
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
public:
    void mergeSort(vector<int> &arr) {
        if(arr.size()==0)
            return;

        vector<int> res = mergeSortCore(arr, 0, arr.size()-1);

        for (int i = 0; i < arr.size(); ++i)
            arr[i] = res[i];

    }



    // 将 result 的 [bgn, mid] 和 [mid + 1, end] 区间合并
    void mergePrem(vector<int> &arr,
                   int bgn, int end,
                   vector<int> &res)
    {
        int mid = (bgn + end)/2;
        int bgn_1 = bgn, end_1 = mid,
            bgn_2 = mid + 1, end_2 = end;

        int index1 = bgn_1;
        int index2 = bgn_2;
        int resIndex = bgn;
        while (index1 <= end_1 && index2 <= end_2) {
            if (arr[index1] <= arr[index2])
                res[resIndex++] = arr[index1++];
            else
                res[resIndex++] = arr[index2++];

        }

        while (index1 <= end_1)
            res[resIndex++] = arr[index1++];

        while (index2 <= end_2)
            res[resIndex++] = arr[index2++];

        for (int i = bgn; i <= end; ++i) {
            arr[i] = res[i];
        }
    }

    void mergeSorePremCore(vector<int> &arr,
                                  int bgn, int end,
                                  vector<int> &res){
        if (bgn == end)
            return;

        int mid = (bgn + end)/2;

        mergeSorePremCore(arr, bgn, mid, res);
        mergeSorePremCore(arr, mid+1, end, res);

        mergePrem(arr, bgn, end, res);
    }

    void mergeSort_prem(vector<int> &arr){
        if (arr.size()==0)
            return;

        vector<int> res(arr.size());
        mergeSorePremCore(arr, 0, arr.size()-1, res);
    }
};

int main(){
    QuickSort sort;
    vector<int> arr = {13, 17, 25, 23, 45, 32, 51, 72};

    sort.quickSort(arr);

    for (int i = 0; i < arr.size(); ++i)
        printf("%d ", arr[i]);

    return 0;
}