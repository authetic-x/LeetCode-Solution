#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

void MirrorOfBT(TreeNode* root) {
    if (root == nullptr) return;
    TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    
    MirrorOfBT(root->left);
    MirrorOfBT(root->right);
}