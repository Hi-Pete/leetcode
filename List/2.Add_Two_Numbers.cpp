// 2. 两数相加
// 给你两个 非空 的链表，表示两个非负的整数
// 它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字
// 请你将两个数相加，并以相同形式返回一个表示和的链表
// 你可以假设除了数字 0 之外，这两个数都不会以 0 开头
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummyNode = new ListNode(0);
        ListNode* pNode = dummyNode;
        while (l1 || l2 || carry) {
            int l1Val = l1 ? l1->val : 0;
            int l2Val = l2 ? l2->val : 0;
            int sum = l1Val + l2Val + carry ;

            carry = sum/10;

            pNode->next = new ListNode(sum % 10);
            l1 = l1? l1->next : nullptr;
            l2 = l2? l2->next : nullptr;
            pNode = pNode->next;
        }

        return dummyNode->next;
    }
};

int main(){
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4, node3);
    ListNode* node2 = new ListNode(2, node4);

    ListNode* node44 = new ListNode(4);
    ListNode* node6 = new ListNode(6, node44);
    ListNode* node5 = new ListNode(5, node6);

    Solution solve;
    ListNode* res = solve.addTwoNumbers(node2, node5);

    return 0;
}