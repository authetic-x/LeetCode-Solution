#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 二叉搜索树的插入删除操作
 *        插入比较简单，因为总是在叶子结点后插入
 *        删除分类：
 *        1. 如果目标结点同时有左子树和右子树，在右子树中找最小值或者
 *           左子树中最大值去替换目标结点的值，在删除右子树或左子树中的结点即可
 *        2. 如果只有左子树或者右子树，直接用左结点或右结点替换即可
 *        3. 叶子结点最好说，直接free
 */

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

void Insert(TreeNode* root, TreeNode* node) {
    if (root == nullptr) {
        root = node;
    } else {
        if (node->val < root->val) {
            Insert(root->left, node);
        } else {
            Insert(root->right, node);
        }
    }
}

TreeNode* FindMin(TreeNode* root) {
    if (root->left == nullptr) return root;
    else FindMin(root->left);
}

TreeNode* Delete(TreeNode* root, int x) {
    if (root == nullptr) return root;
    if (root->val == x) {
        if (root->left != nullptr && root->right != nullptr) {
            TreeNode* tmp = FindMin(root->right);
            root->val = tmp->val;
            root->right = Delete(root->right, tmp->val);
        } else {
            TreeNode* tmp = root;
            if (root->left != nullptr) {
                root = root->left;
            } else if (root->right != nullptr) {
                root = root->right;
            }
            free(tmp);
        }
    } else if (x < root->val) {
        Delete(root->left, x);
    } else {
        Delete(root->right, x);
    }
    return root;
}