// 92. Reverse Linked List II
// 反转从位置 m 到 n 的链表
// 请使用一趟扫描完成反转
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummyNode = new ListNode(0, head);

        ListNode* pLast = dummyNode;
        for (int i = 0; i < m-1 ; ++i)
             pLast = pLast->next;
        // pLast 是第 m-1 个；pPrev 是第 m 个
        ListNode* pPrev = pLast->next;
        // pNode 是第 m+1 个
        ListNode* pNode = pPrev->next;
        for (int j = 0; j < n - m; ++j) {
            // head 指针借来当 next 指针
            head = pNode->next;
            pNode->next = pPrev;

            pPrev = pNode;
            pNode = head;
        }
        pLast->next->next = pNode;
        pLast->next = pPrev;

        return dummyNode->next;
    }
};

int main(){
    ListNode* ListNode6 = new ListNode(6);
    ListNode* ListNode5 = new ListNode(5, ListNode6);
    ListNode* ListNode4 = new ListNode(4, ListNode5);
    ListNode* ListNode3 = new ListNode(3, ListNode4);
    ListNode* ListNode2 = new ListNode(2, ListNode3);
    ListNode* ListNode1 = new ListNode(1, ListNode2);

    Solution Solve_test = Solution();

    ListNode* result =Solve_test.reverseBetween(ListNode1, 2, 4);

    delete ListNode1, ListNode2, ListNode3, ListNode4, ListNode5, ListNode6;

    return 0;
}