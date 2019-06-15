#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

bool hasSubTree(TreeNode* root1, TreeNode* root2) {
    if (root2 == nullptr) return true;
    if (root1 == nullptr) return false;
    if (root1->val == root2->val) {
        if (core(root1, root2)) {
            return true;
        }
    }
    return hasSubTree(root1->left, root2)
            || hasSubTree(root1->right, root2);
}

bool core(TreeNode* root1, TreeNode* root2) {
    if (root2 == nullptr) return true;
    if (root1 == nullptr) return false;
    if (root1->val == root2->val) {
        return core(root1->left, root2->left) &&
                core(root1->right, root2->right);
    }
    return false;
}