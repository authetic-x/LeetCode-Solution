#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == p || root == q) return root;
    TreeNode* left = LCA(root->left, p, q);
    TreeNode* right = LCA(root->right, p, q);
    if (left != nullptr && right != nullptr) return root;
    return left != nullptr ? left : right;
}