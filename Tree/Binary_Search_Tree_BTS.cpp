// 二叉查找树(Binary Search Tree, BST) 是一种特殊的二叉树:
// 对于每个父节点,其左子节点的值小于等于父结点的值,其右子节点的值大于等于父结点的值
// 因此对于一个二叉查找树,我们可以在 O(nlogn) 的时间内查找一个值是否存在:
// 从根节点开始:  若当前节点的值大于查找值则向左下走,
//              若当前节点的值小于查找值则向右下走
// 同时因为二叉查找树是有序的,对其中序遍历的结果即为排好序的数组

template <class T>
class BST{
    struct Node {
        T data;
        Node* left;
        Node* right;
    };

    Node* root;

    Node* makeEmpty(Node* t) {
        if (t == nullptr)
            return nullptr;

        makeEmpty(t->left);
        makeEmpty(t->right);

        // 后需遍历删除节点
        delete t;

        return nullptr;
    }

    Node* insert(Node* t, T x) {
        if (t == nullptr) {
            t = new Node;
            t->data = x;
            t->left = t->right = nullptr;
        }
        else if (x < t->data)
            t->left = insert(t->left, x);

        else if (x > t->data)
            t->right = insert(t->right, x);

        return t;
    }

    Node* find(Node* t, T x) {
        if (t == nullptr)
            return nullptr;

        if (x < t->data)
            return find(t->left, x);

        if (x > t->data)
            return find(t->right, x);

        return t;
    }

    Node* findMin(Node* t) {
        if (t == nullptr || t->left == nullptr)
            return t;

        return findMin(t->left);
    }

    Node* findMax(Node* t) {
        if (t == nullptr || t->right == nullptr)
            return t;

        return findMax(t->right);
    }

    Node* remove(Node* t, T x) {
        Node* temp;

        if (t == nullptr)
            return nullptr;

        else if (x < t->data)
            t->left = remove(t->left, x);

        else if (x > t->data)
            t->right = remove(t->right, x);

        else if (t->left && t->right) {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->right, t->data);
        }
        else {
            temp = t;

            if (t->left == nullptr)
                t = t->right;

            else if (t->right == nullptr)
                t = t->left;

            delete temp;
        }
        return t;
    }

  public:
    BST(): root(nullptr) {}

    ~BST() {
        root = makeEmpty(root);
    }

    void insert(T x) {
        insert(root, x);
    }

    void remove(T x) {
        remove(root, x);
    }
};

