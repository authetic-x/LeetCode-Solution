#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

/*
 *  Info: 将二叉搜索树转换为双向链表，
 *        中序遍历的复杂应用
 */

TreeNode* convert(TreeNode* root) {
    if (root == nullptr) return nullptr;
    TreeNode* lastNode = nullptr;
    convertCore(root, lastNode);
    TreeNode* head = lastNode;
    while (head->left != nullptr) {
        head = head->left;
    }
    return head;
}

void convertCore(TreeNode* root, TreeNode* &lastNode) {
    if (root == nullptr) return;
    convertCore(root->left, lastNode);
    root->left = lastNode;
    if (lastNode != nullptr) {
        lastNode->right = root;
    }
    lastNode = root;
    convertCore(root->right, lastNode);
}