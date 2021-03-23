// 147. Insertion Sort List(Medium)
// 对链表进行插入排序
//


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head)
            return head;

        ListNode* dummynode = new ListNode(0);
        dummynode->next = head;

        // 记录已排序完成的结点末尾
        ListNode* lastSorted = head;
        // 待插入节点
        ListNode* pNode = head->next;
        while(pNode) {
            if (lastSorted->val <= pNode->val)
                // 无须插入
                lastSorted = lastSorted->next;
            else {
                // 寻找待插入位置
                ListNode* pPrev = dummynode;
                while (pPrev->next->val <= pNode->val)
                    pPrev = pPrev->next;

                lastSorted->next = pNode->next;
                pNode->next = pPrev->next;
                pPrev->next = pNode;
            }
            pNode = lastSorted->next;
        }

        return dummynode->next;
    }
};