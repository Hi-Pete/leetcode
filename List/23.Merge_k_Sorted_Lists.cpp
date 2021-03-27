// 23. 合并K个升序链表
// 给你一个链表数组，每个链表都已经按升序排列
// 请你将所有链表合并到一个升序链表中，返回合并后的链表
//

#include <vector>
#include <climits>

using std::vector;

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

        return mergeTwoLists(merge(lists, bgn, mid), merge(lists, mid + 1, end));
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        return merge(lists, 0, lists.size()-1);
    }
};

class PriorQueue {

};