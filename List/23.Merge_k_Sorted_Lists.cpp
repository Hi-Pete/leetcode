// 23. 合并K个升序链表
// 给你一个链表数组，每个链表都已经按升序排列
// 请你将所有链表合并到一个升序链表中，返回合并后的链表
//

#include <vector>
#include <queue>
#include <climits>

using std::vector;
using std::priority_queue;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MergeSort {
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummyNode = new ListNode(0);
        ListNode* pNode = dummyNode;

        while (l1 && l2){
            if (l1->val <= l2->val){
                pNode->next = l1;
                l1 = l1->next;
            } else{
                pNode->next = l2;
                l2 = l2->next;
            }
            pNode = pNode->next;
        }
        pNode->next = l1 ? l1 : l2;
        return dummyNode->next;
    }

    ListNode* merge(vector<ListNode*>& lists, int bgn, int end) {
        if (bgn == end)
            return lists[bgn];
        if (bgn > end)
            return nullptr;

        int mid = (bgn + end) >> 1;

        // 后序遍历位，两两切分链表 归并融合
        return mergeTwoLists(merge(lists, bgn, mid), merge(lists, mid + 1, end));
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        return merge(lists, 0, lists.size()-1);
    }
};

class PriorQueue {
    static bool comparelstNode(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* pNode = dummyHead;

        int k = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, decltype(comparelstNode) *> min_Heap(comparelstNode);
        // 所有链表头节点入队
        for (int i = 0; i < k; ++i)
            if(lists[i])
                min_Heap.push(lists[i]);

        // 在大小为　ｋ　的最小堆中滚动向结果链表压入当前最小值
        while (!min_Heap.empty()){
            ListNode* node = min_Heap.top();
            min_Heap.pop();

            pNode->next = node;
            pNode = pNode->next;

            if(node->next)
                min_Heap.push(node->next);
        }

        return dummyHead->next;
    }

};