#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

TreeNode* KNumInBST(TreeNode* root, int k) {
    if (root == nullptr) return root;
    TreeNode* ans;
    Core(root, k, ans);
    return ans;
}

void Core(TreeNode* root, int &k, TreeNode* &ans) {
    if (root == nullptr || k == 0) return;
    Core(root->left, k, ans);
    k--;
    if (k == 0) ans = root;
    Core(root->right, k, ans);
}