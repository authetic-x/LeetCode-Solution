#include "stdio.h"

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

Node* createNode() {
    Tree[loc].lchild = Tree[loc].rchild = nullptr;
    return &Tree[loc++];
}



int main() {

}