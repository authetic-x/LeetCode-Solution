#include "stdio.h"
#include "stdlib.h"

// 树的遍历，递归到非递归

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

// 递归遍历比较简单
void PreOrder(TreeNode* root) {
    if (root == nullptr)
        return;
    printf("%d", root->val);
    PreOrder(root->left);
    PreOrder(root->right);
}

// 层次遍历
void CentiOrder(TreeNode* root) {
    if (root == nullptr)
        return;
    
}