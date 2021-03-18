// 142. Linked List Cycle II
// 给定一个链表，返回链表开始入环的第一个节点
// 如果链表无环，则返回 null
// 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）
// 如果 pos 是 -1，则在该链表中没有环
// 注意，pos 仅仅是用于标识环的情况，并不会作为参数传递到函数中
// 说明：不允许修改给定的链表

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * @brief Floyd Cycle Detection Algorithm
 * 快慢指针，快指针每次走两步，慢指针一次走一步
 * 如果不含环，跑得快的指针最终会遇到 nullptr
 * 如果含环，快慢指针会相遇
 *
 * 假设相遇时慢指针走了 k 步， 快指针则走了 2k 步
 * 而 k 一定为环的整数倍
 * 假设相遇点距起点的距离为 m ，那么环的起点距头节点的距离为 k-m
 * 而从相遇点前进 k-m 也能达到环节点
 * 所以相遇时把一个指针移到头节点，以相同速度前进
 * 下次相遇时就是环节点
 * @param head 头节点
 * @return fast 环起点
 */
ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    // 判断是否存在环路
    do {
        if (!fast || !fast->next)
            return nullptr;     // 检查 fast 是否到尽头
        fast = fast->next->next;
        slow = slow->next;
    } while (fast != slow);

    // 如果存在,查找环路节点
    fast = head;
    while (fast != slow){
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}

