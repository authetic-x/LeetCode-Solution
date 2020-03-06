#include "stdio.h"
#include "string.h"

/*
    判断两个序列组成的二叉排序树是否相同
    思路是：建立BST，然后比较它们的前序和中序遍历序列是否相同
*/

struct Node {
    Node* lchild;
    Node* rchild;
    int val;
}Tree[110];

int loc;
// 保存遍历后的结果
char str1[25], str2[25];
int *size;
int size1, size2;
char *str;

Node* createNode() {
    Tree[loc].lchild = Tree[loc].rchild = nullptr;
    return &Tree[loc++];
}

Node* Insert(Node* root, int x) {
    if (root == NULL) {
        root = &Tree[loc++];
        root->val = x;
    } else if (x < root->val) {
        root->lchild = Insert(root->lchild, x);
    } else {
        root->rchild = Insert(root->rchild, x);
    }
    return root;
}

void preOrder(Node* root) {
    if (root != NULL) {
        str[(*size)++] = root->val;
        preOrder(root->lchild);
        preOrder(root->rchild);
    }
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->lchild);
        str[(*size)++] = root->val;
        inOrder(root->rchild);
    }
}

int main() {
    int n;
    char tmp[12];
    while (scanf("%d", &n) != EOF && n != 0) {
        loc = 0;
        Node* T = NULL;
        scanf("%s", tmp);
        for (int i = 0; tmp[i] != 0; i ++ ) {
            T = Insert(T, tmp[i]-'0');
        }
        size1 = 0;
        size = &size1;
        str = str1;
        // 当前序和中序遍历的结果保存在一个数组里
        preOrder(T);
        inOrder(T);
        str1[size1] = 0;
        while (n--) {
            scanf("%s", tmp);
            Node* T = NULL;
            for (int i = 0; tmp[i] != 0; i ++ ) {
                T = Insert(T, tmp[i]-'0');
            }
            size2 = 0;
            size = &size2;
            str = str2;
            preOrder(T);
            inOrder(T);
            str2[size2] = 0;
            puts(strcmp(str1, str2) == 0 ? "YES" : "NO");
        }
    }
    return 0;
}