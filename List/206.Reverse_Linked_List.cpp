// 206. 反转链表
// 反转一个单链表
//

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Iteratively {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pPrev = nullptr;

        while(head != nullptr) {
            // 将 head 和 pPrev 反转
            // head 和 pPrev 向后移动
            ListNode* pNext = head->next;
            head->next = pPrev;
            pPrev = head;
            head = pNext;
        }

        return pPrev;
    }
};

class Recursively {
public:
    // 输入一个节点head
    // 将「以head为起点」的链表反转
    // 返回反转之后的头结点
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* pPrev = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return pPrev;
    }
};