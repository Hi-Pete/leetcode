// 24. 两两交换链表中的节点
// 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表
// 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换
//

 struct ListNode {
     int val;
     ListNode *next;

     ListNode() : val(0), next(nullptr) {}

     ListNode(int x) : val(x), next(nullptr) {}

     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Recursively {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* pNode = head->next;
        head->next = swapPairs(pNode->next);
        pNode->next = head;

        return pNode;
    }
};

class Iteratively {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;

        ListNode* dummyNode = new ListNode(0, head);
        ListNode* pNode = dummyNode;

        while (pNode->next && pNode->next->next){
            ListNode* pNext = pNode->next->next;
            pNode->next->next = pNext->next;
            pNext->next = pNode->next;
            pNode->next = pNext;

            pNode = pNext->next;
        }

        return dummyNode->next;
    }

};

int main(){
    ListNode* node4 = new ListNode(4);
    ListNode* node3 = new ListNode(3, node4);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* node1 = new ListNode(1, node2);

    Iteratively solve;

    ListNode* res = solve.swapPairs(node1);

    return 0;
}