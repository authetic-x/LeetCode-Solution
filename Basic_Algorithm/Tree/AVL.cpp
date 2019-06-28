#include <bits/stdc++.h>
using namespace std;

// 平衡二叉树建立在二叉搜索树之上，保证了每个结点的左子树
// 和右子树平衡因子差的绝对值不超过1，其中左子树与右子树的高度之差
// 成为该结点的平衡因子

struct Node {
    // height为当前结点的子树高度，初始值为1
    int val, height;
    Node* lchild;
    Node* rchild;
};

Node* newNode(int val) {
    Node* node = new Node;
    node->val = val;
    node->height = 1;
    node->lchild = node->rchild = nullptr;
    return node;
}

int getHeight(Node* root) {
    if (root == nullptr) return 0;
    return root->height;
}

int getBalancedFactor(Node* root) {
    return getHeight(root->lchild) - getHeight(root->rchild);
}

void updateHeight(Node* root) {
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

Node* search(Node* root, int x) {
    if (root == nullptr) return nullptr;
    if (root->val == x) return root;
    else if (root->val > x) search(root->lchild, x);
    else search(root->rchild, x);
}

// 左旋
void L(Node* &root) {
    Node* tmp = root->rchild;
    root->rchild = tmp->lchild;
    tmp->lchild = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}

// 右旋
void R(Node* &root) {
    Node* tmp = root->lchild;
    root->lchild = tmp->rchild;
    tmp->rchild = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}

// 插入的关键是检查是否出现了LL型，LR型，RL型，RR型
// 将LR型，RL型分别旋转为LL型和RR型在进行总体旋转
void insert(Node* root, int v) {
    if (root == nullptr) {
        root = newNode(v);
        return;
    }
    if (v < root->val) {
        insert(root->lchild, v);
        updateHeight(root);
        if (getBalancedFactor(root) == 2) {
            if (getBalancedFactor(root->lchild) == 1) {
                R(root);
            } else if (getBalancedFactor(root->lchild) == -1){
                L(root->lchild);
                R(root);
            }
        }
    } else {
        insert(root->rchild, v);
        updateHeight(root);
        if (getBalancedFactor(root) == -2) {
            if (getBalancedFactor(root->rchild) == -1) {
                L(root);
            } else if (getBalancedFactor(root->rchild) == 1) {
                R(root->rchild);
                L(root);
            }
        }
    }
}