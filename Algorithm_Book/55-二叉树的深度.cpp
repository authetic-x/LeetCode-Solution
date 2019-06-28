#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

int TreeDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    int lDepth = TreeDepth(root->left);
    int rDepth = TreeDepth(root->right);
    return (lDepth > rDepth) ? (lDepth+1) : (rDepth+1);
}