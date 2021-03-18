// 116. Populating Next Right Pointers in Each Node
// 给定一个完美二叉树, 其所有叶子节点都在同一层，每个父节点都有两个子节点
// 填充它的每个 next 指针, 让这个指针指向其下一个右侧节点
// 如果找不到下一个右侧节点，则将 next 指针设置为 NULL
// 初始状态下，所有 next 指针都被设置为 NULL

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    void connectTwoNode(Node* node1, Node* node2){
        if (!node1 || !node2)
            return;

        node1->next = node2;

        connectTwoNode(node1->left, node1->right);
        connectTwoNode(node2->left, node2->right);
        connectTwoNode(node1->right, node2->left);
    }

    Node* connect(Node* root) {
        if (!root)
            return nullptr;

        connectTwoNode(root->left, root->right);
        return root;
    }
};

