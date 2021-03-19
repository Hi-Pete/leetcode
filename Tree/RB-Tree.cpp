//
// Created by hipete on 21-3-19.
//

#include <utility>

static bool RED = true;
static bool BLACK = false;

struct RB_Node{
    std::pair<int, int> val;
    RB_Node* left;
    RB_Node* right;
    int N;
    bool color;

    RB_Node(int key, int value, int N, bool color) {
        this->val.first = key;
        this->val.second = value;
        this->N = N;
        this->color = color;
    }

    int size(){
        return this->N;
    }
};

bool isRed(RB_Node* x){
    if (!x)
        return false;

    return x->color == RED;
}

RB_Node* rotateLeft(RB_Node* h){
    RB_Node* x = h->right;
    h->right = x->left;
    x->left = h;

    x->color = h->color;
    h->color = RED;

    x->N = h->N;
    h->N = 1 + h->left->size() + h->right->size();

    return x;
}

RB_Node* rotateRight(RB_Node* h){
    RB_Node* x = h->left;
    h->left = x->right;
    x->right = h;

    x->color = h->color;
    h->color = RED;

    x->N = h->N;
    h->N = 1 + h->left->size() + h->right->size();

    return x;
}

class RedBlackBST{
    RB_Node *root;

    bool isRed(RB_Node* x){
        if (!x)
            return false;

        return x->color == RED;
    }

    RB_Node* rotateLeft(RB_Node* h){
        RB_Node* x = h->right;
        h->right = x->left;
        x->left = h;

        x->color = h->color;
        h->color = RED;

        x->N = h->N;
        h->N = 1 + h->left->size() + h->right->size();

        return x;
    }

    RB_Node* rotateRight(RB_Node* h){
        RB_Node* x = h->left;
        h->left = x->right;
        x->right = h;

        x->color = h->color;
        h->color = RED;

        x->N = h->N;
        h->N = 1 + h->left->size() + h->right->size();

        return x;
    }

    void flipColors(RB_Node* h){
        h->color = RED;
        h->left->color = BLACK;
        h->right->color = BLACK;
    }

    RB_Node* put(RB_Node* h, int key, int value){
        if (!h)     // Do standard insert
                    // with red link to parent.
            return new RB_Node(key, value, 1, RED);

        if (key > h->val.first)
            h->left = put(h->left, key, value);
        else if (key < h->val.first)
            h->right = put(h->right, key, value);
        else h->val.second = value;

        if(isRed(h->right) && !isRed(h->left))
            h = rotateLeft(h);
        if(isRed(h->left) && isRed(h->left->left))
            h = rotateRight(h);
        if(isRed(h->left) && isRed(h->right))
            flipColors(h);

        h->N = h->left->size() + h->right->size() + 1;

        return h;
    }

public:
    void put(int key, int value){
        root = put(root, key, value);
        root->color = BLACK;
    }

};