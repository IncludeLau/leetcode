#include <iostream>
#include <stack>

struct Tree {
    Tree* lson;
    Tree* rson;
    int data;

    Tree(){}
    explicit Tree(int d) {data=d; lson = nullptr; rson = nullptr;}
};

void createBtiTree(Tree* &tree) {
    int data;
    std::cin >> data;
    if(data == -1) {
        tree = nullptr;
    }else {
        tree = new Tree();
        tree->data = data;
        createBtiTree(tree->lson);
        createBtiTree(tree->rson);
    }
}


void preOrderRecur(Tree *tree) {
    if(tree == nullptr) return;
    std::cout << tree->data << " ";
    preOrderRecur(tree->lson);
    preOrderRecur(tree->rson);
}

void inOrderRecur(Tree *tree) {
    if(tree  == nullptr) return;
    preOrderRecur(tree->lson);
    std::cout << tree->data << " ";
    preOrderRecur(tree->rson);
}

void posOrderRecur(Tree* tree) {
    if(tree == nullptr) return;
    posOrderRecur(tree->lson);
    posOrderRecur(tree->rson);
    std::cout << tree->data << " ";
}


void preOrderNoRecur(Tree * tree) {
    if (tree == nullptr) return;
    std::stack<Tree* > sta;
    sta.push(tree);
    while (!sta.empty()) {
        Tree* cur = sta.top();
        sta.pop();
        std::cout << cur->data << " ";
        if(cur->lson != nullptr) sta.push(cur->lson);
        if(cur->rson != nullptr) sta.push(cur->rson);
    }
}

void inOrderNoRecur(Tree * tree) {
    if (tree == nullptr) return;
    std::stack<Tree*> sta;
    Tree* p = tree;
    while (p || !sta.empty()) {
        while (p) {
            sta.push(p);
            p = p->lson;
        }
        if(!sta.empty()) {
            p = sta.top();
            sta.pop();
            std::cout << p->data << " ";
            p = p->rson;
        }
    }
}


void posOrderNoRecur(Tree * tree) {
    if(tree == nullptr) return;
    std::stack<Tree*> sta;

    Tree* pre = nullptr;
    sta.push(tree);
    while (!sta.empty()) {
        Tree *p = sta.top();
        if ((p->lson == nullptr && p->rson == nullptr) ||
                (pre != nullptr && (pre == p->lson || pre == p->rson))){
            std::cout << p->data << " ";
            sta.pop();
            pre = p;
        }else {
            if(p->rson != nullptr) {
                sta.push(p->rson);
            }
            if(p->lson != nullptr) {
                sta.push(p->lson);
            }
        }
    }
}