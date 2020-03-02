#include "stdio.h"

struct Node {
    Node* lchild;
    Node* rchild;
    int val;
}Tree[110];

int loc;

Node* createNode() {
    Tree[loc].lchild = Tree[loc].rchild = nullptr;
    return &Tree[loc++];
}

Node* Insert(Node* node, int x) {
    if (node == NULL) {
        node = createNode();
        node->val = x;
    } else if (node->val > x) {
        node->lchild = Insert(node->lchild, x);
    } else {
        node->rchild = Insert(node->rchild, x);
    }
    return node;
}

void preOrder(Node* root) {
    if (root != NULL) {
        printf("%d", root->val);
        preOrder(root->lchild);
        preOrder(root->rchild);
    }
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->lchild);
        printf("%d", root->val);
        inOrder(root->rchild);
    }
}

void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->lchild);
        postOrder(root->rchild);
        printf("%d", root->val);
    }
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        Node* root = NULL;
        loc = 0;
        for (int i = 0; i < n; i ++ ) {
            int x;
            scanf("%d", &x);
            root = Insert(root, x);
        }
        preOrder(root);
        printf("\n");
        inOrder(root);
        printf("\n");
        postOrder(root);
        printf("\n");
    }
    return 0;
}