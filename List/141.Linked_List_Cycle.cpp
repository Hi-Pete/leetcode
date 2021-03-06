// 141. 环形链表
// 给定一个链表 , 判断链表中是否有环
// 如果链表中有某个节点 , 可以通过连续跟踪 next 指针再次到达 , 则链表中存在环
// 为了表示给定链表中的环 , 我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）
// 如果 pos 是 -1 , 则在该链表中没有环
// 注意：pos 不作为参数进行传递 , 仅仅是为了标识链表的实际情况
// 如果链表中存在环则返回 true , 否则返回 false
//

#include <lzma.h>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;

        ListNode* fast, *slow;
        fast = slow = head;

        while (fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;

            if(fast == slow)
                return true;
        }
        return false;
    }
};
