// 143. 重排链表
// 给定一个单链表 L：L0→L1→…→Ln-1→Ln
// 将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
// 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换
//

#include <proj_api.h>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head)
            return;

        ListNode* pTail, *pMid;
        pTail = pMid = head;

        while (pTail->next){
            pMid = pMid->next;
            pTail = pTail->next;

            if (pTail->next)
                pTail = pTail->next;
        }

        ListNode* pNode = pMid->next;
        pMid->next = nullptr;
        while (pNode){
            ListNode* pNext = pNode->next;
            pNode->next = pMid;
            pMid = pNode;
            pNode = pNext;
        }

        pNode = head;
        while (pNode){
            ListNode* pNext = pNode->next;
            pNode->next = pMid;
            ListNode* pNext2 = nullptr;
            if(pMid){
                pNext2 = pMid->next;
                pMid->next = pNext;
            }

            pNode = pNext;
            pMid = pNext2;
        }
    }
};