// 234. 回文链表
// 判断一个链表是否为回文链表
//
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head){
        ListNode* pPrev;
        pPrev = nullptr;
        while(head){
            ListNode* pNext = head->next;
            head->next = pPrev;
            pPrev = head;
            head = pNext;
        }
        return pPrev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* pFast, *pSlow;
        pFast = pSlow = head;

        while(pFast && pFast->next){
            pFast = pFast->next->next;
            pSlow = pSlow->next;
        }

        pFast = reverseList(pSlow);
        while(pFast){
            if (pFast->val != head->val)
                return false;
            pFast = pFast->next;
            head = head->next;
        }
        if(!pFast)
            return true;
        return false;

    }
};