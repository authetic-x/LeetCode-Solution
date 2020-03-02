#include "stdio.h"
#include "string.h"

/*
    程序测试运行有问题
*/

struct Node {
    Node* lchild;
    Node* rchild;
    char val;
}Tree[50];

// 已使用的节点个数
int loc;

char str1[30], str2[30];

Node* createNode() {
    Tree[loc].lchild = Tree[loc].rchild = nullptr;
    return &Tree[loc++];
}

Node* buildTree(int s1, int s2, int e1, int e2) {
    Node* root = createNode();
    root->val = str1[s1];
    int rootIdx;
    for (int i = s2; i <= e2; i ++ ) {
        if (str2[i] == root->val) {
            rootIdx = i;
            break;
        }
    }
    // 左子树不为空
    if (rootIdx != s2) {
        root->lchild = buildTree(s1+1, s1+(rootIdx-s2), s2, rootIdx-1);
    }
    // 右子树不为空
    if (rootIdx != e2) {
        root->rchild = buildTree(s1+(rootIdx-s2)+1, e1, rootIdx+1, e2);
    }
    return root;
}

void PostOrder(Node* root) {
    if (root != nullptr) {
        PostOrder(root->lchild);
        PostOrder(root->rchild);
        printf("%c", root->val);
    }
}

int main() {
    while (scanf("%s", str1) != EOF) {
        scanf("%s", str2);
        int L1 = strlen(str1);
        int L2 = strlen(str2);
        Node* root = buildTree(0, L1-1, 0, L2-1);
        PostOrder(root);
        printf("\n");
    }
}