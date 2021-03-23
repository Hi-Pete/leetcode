// 148. 排序链表
// 给你链表的头结点 head
// 请将其按 升序 排列并返回 排序后的链表
//

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    ListNode* merge(ListNode* h1, ListNode* h2){
        ListNode* dummyNode = new ListNode(0);
        ListNode* pNode = dummyNode;

        while(h1 && h2){
            if(h1->val < h2->val){
                pNode->next = h1;
                h1 = h1->next;
            } else{
                pNode->next = h2;
                h2 = h2->next;
            }
            pNode = pNode->next;
        }
        pNode->next = h1? h1 : h2;

        return dummyNode->next;
    }

public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* head2 = slow->next;
        slow->next = nullptr;

        return merge(sortList(head), sortList(head2));
    }
};