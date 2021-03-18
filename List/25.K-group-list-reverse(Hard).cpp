// 25. K个一组翻转链表
// 给你一个链表，每 K 个节点一组进行翻转，请你返回翻转后的链表
// K 是一个正整数，它的值小于或等于链表的长度
// 如果节点总数不是 K 的整数倍，那么请将最后剩余的节点保持原有顺序

#include <utility>

struct ListNode{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    // 翻转一个子链表，并且返回新的头与尾
    std::pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail)
    {
        ListNode* prev = tail->next;    // prev 指针指向尾节点后一个节点
                                        // 注：prev 指针的初值指向翻转数组尾节点要指向的地方
        ListNode* curr = head;          // 从头节点开始

        while (prev != tail)
        {
            ListNode* nex = curr->next; // nex 指针接管 curr 的 next
            curr->next = prev;          // 把第一个节点的 next 链接到尾节点后一个节点
            prev = curr;                // prev 和 curr 向后移动一位
            curr = nex;
        }
        return {tail, head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // 创建一个虚假的头节点，指针存储头指针
        ListNode* dummyNode = new ListNode(0);
        hair->next = head;

        ListNode* pre = dummyNode;       // 指针 pre 指向假头节点
                                    // 之后 head 指针和 pre 指针作为双指针辅助翻转链表
        while (head)
        {
            // tail 指针首先用来判断剩余的部分是否有 k 个节点可以翻转
            // 如果有的话，tail 指针定位 k 区间尾部
            ListNode* tail = pre;

            for (int i = 0; i < k; ++i) {
                tail = tail->next;

                if (!tail)
                    return dummyNode->next;
            }

            std::pair<ListNode*, ListNode*> result = myReverse(head, tail);
            head = result.first;        // head 和 tail 保存反转后的节点
            tail = result.second;       // C++17 的写法：
                                        // tie(head, tail) = myReverse(head, tail);
            // 原链表前一个节点的指针指向翻转后的头节点
            pre->next = head;

            // pre 和 head 移动指向下一段待处理链表
            pre = tail;
            head = tail->next;
        }

        return dummyNode->next;
    }
};

int main(){
    ListNode* ListNode10 = new ListNode(10);
    ListNode* ListNode9  = new ListNode(9, ListNode10);
    ListNode* ListNode8  = new ListNode(8, ListNode9);
    ListNode* ListNode7  = new ListNode(7, ListNode8);
    ListNode* ListNode6  = new ListNode(6, ListNode7);
    ListNode* ListNode5  = new ListNode(5, ListNode6);

    Solution Solve_test = Solution();

    ListNode* result =Solve_test.reverseKGroup(ListNode5, 3);

    delete ListNode10, ListNode9, ListNode8, ListNode7, ListNode6, ListNode5;

    return 0;
}