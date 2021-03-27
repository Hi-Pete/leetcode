// 优先队列 priority queue
// 优先队列常常用堆(Heap)来实现
// 堆是一个完全二叉树,其每个节点的值总是大于等于子节点的值
// 实际实现堆时,我们通常用一个数组而不是用指针建立一个树
// 因为堆是完全二叉树,所以用数组表示时：
//                  索引为 i 的节点的父节点下标一定为 (i-1)/2  (若 i 从 1 开始，则 i/2)
//                          其左侧子节点的下标一定为 2i+1     (若 i 从 1 开始，则 2i )
//                          其右侧子节点的下标一定为 2i+2     (若 i 从 1 开始，则 2i+1)
//                  数组中每个元素的优先级都必须高于它两侧子节点
// 最核心的两个操作是上浮和下沉：
//      如果一个节点比父节点大,那么需要交换这个两个节点。交换后还可能比它新的父节点大,因此需要不断地进行比较和交换操作,我们称之为上浮
//      类似地,如果一个节点比父节小,也需要不断地向下进行比较和交换操作,我们称之为下沉。如果一个节点有两个子节点,我们总是交换最大的子节点
//

#include <vector>

std::vector<int> heap;
// 获得最大值
int top() {
    return heap[0];
}

// 上浮
void swim(int pos) {
    while (pos > 1 && heap[pos/2] < heap[pos]) {
        std::swap(heap[pos/2], heap[pos]);
        pos /= 2;
    }
}

// 下沉
void sink(int pos) {
    while (2 * pos <= heap.size()) {
        int i = 2 * pos;

        if (i < heap.size() && heap[i] < heap[i+1])
            ++i;

        if (heap[pos] >= heap[i])
            break;

        std::swap(heap[pos], heap[i]);
        pos = i;
    }
}

// 插入任意值：把新的数字放在最后一位， 然后上浮
void push(int k) {
    heap.push_back(k);
    swim(heap.size() - 1);
}

// 删除最大值：把最后一个数字挪到开头， 然后下沉
void pop() {
    heap[0] = heap.back();
    heap.pop_back();
    sink(0);
}

