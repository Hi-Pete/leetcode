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

class Iteratively {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummyNode = new ListNode(0, head);

        ListNode* pLast = dummyNode;
        for (int i = 0; i < m-1 ; ++i)
             pLast = pLast->next;
        // pLast 是第 m-1 个节点
        // pPrev 是第 m 个节点
        ListNode* pPrev = pLast->next;
        // pNode 是第 m+1 个
        ListNode* pNode = pPrev->next;

        // 该 n-m 条边
        for (int j = 0; j < n - m; ++j) {
            // head 指针借来当 next 指针
            head = pNode->next;
            pNode->next = pPrev;

            pPrev = pNode;
            pNode = head;
        }
        // pLast 为 m-1 ，pNode 为 n+1
        pLast->next->next = pNode;
        pLast->next = pPrev;

        return dummyNode->next;
    }
};

class Recursively {
    ListNode* successor = nullptr;
public:
    // 反转前 n 个节点
    ListNode* reverseN(ListNode* head, int n) {
        if(n==1) {
            // 记录后驱节点
            successor = head->next;

            return head;
        }
        // 以 head.next 为起点，需要反转前 n - 1 个节点
        ListNode* pPrev = reverseN(head->next, n-1);

        head->next->next = head;
        head->next = successor;

        return pPrev;
    }

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // 移动到 m 个节点
        // 反转以 m 个节点为头的 list 的前 n-m 个节点
        if (m==1)
            return reverseN(head, n);

        head->next = reverseBetween(head->next, m-1, n-1);

        return head;
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