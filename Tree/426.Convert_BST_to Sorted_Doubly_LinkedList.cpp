// 426. 将二叉搜索树转化为排序的双向链表
// 将一个 二叉搜索树 就地转化为一个 已排序的双向循环链表
// 对于双向循环列表，你可以将左右孩子指针作为双向循环链表的前驱和后继指针
// 第一个节点的前驱是最后一个节点，最后一个节点的后继是第一个节点
// 特别地，我们希望可以 就地 完成转换操作
// 当转化完成以后，树中节点的左指针需要指向前驱，树中节点的右指针需要指向后继
// 还需要返回链表中最小元素的指针
//

#include <iostream>

class Node {
public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }

    Node(int _val, Node *_left, Node *_right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
    void convert(Node* pNode, Node** pLastNodeInList){
        if(!pNode)
            return;

        if(pNode->left)
            convert(pNode->left, pLastNodeInList);

        // 中序遍历
        pNode->left = *pLastNodeInList;
        (*pLastNodeInList)->right = pNode;
        *pLastNodeInList = pNode;

        if(pNode->right)
            convert(pNode->right, pLastNodeInList);
    }
public:
    Node* treeToDoublyList(Node* root) {
        if (!root)
            return nullptr;

        Node dummyNode(0, nullptr, nullptr);
        Node* pLastNodeInList = &dummyNode;

        convert(root, &pLastNodeInList);

        dummyNode.right->left = pLastNodeInList;
        pLastNodeInList->right = dummyNode.right;

        return dummyNode.right;
    }
};

int main(){
    Node* node1 = new Node(1);
    Node* node3 = new Node(3);
    Node* node5 = new Node(5);

    Node* node2 = new Node(2, node1, node3);

    Node* node4 = new Node(4, node2, node5);

    Solution solve;
    Node* res = solve.treeToDoublyList(node4);

    while (res){
        std::cout << res->val;
        res = res->right;
    }

    return 0;

}