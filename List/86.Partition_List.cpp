// 86. 分隔链表
// 给你一个链表的头节点 head 和一个特定值 x
// 请你对链表进行分隔，使得所有小于 x 的节点都出现在大于或等于 x 的节点之前
// 你应当保留两个分区中每个节点的初始相对位置
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
    ListNode* partition(ListNode* head, int x) {
        if (!head)
            return head;

        ListNode* dummyNode1 = new ListNode(0);
        ListNode* node1 = dummyNode1;
        ListNode* dummyNode2 = new ListNode(0);
        ListNode* node2 = dummyNode2;

        ListNode* pNode = head;
        while (pNode) {
            if (pNode->val >= x){
                node2->next = pNode;
                node2 = node2->next;
            } else{
                node1->next = pNode;
                node1 = node1->next;
            }

            pNode = pNode->next;
        }
        node2->next = nullptr;      // notice
        node1->next = dummyNode2->next;

        return dummyNode1->next;
    }
};

int main(){

}