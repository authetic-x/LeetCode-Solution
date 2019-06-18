#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

bool isSymmetric(TreeNode* root) {
    return isSymmetricCore(root, root);
}

bool isSymmetricCore(TreeNode* t1, TreeNode* t2) {
    if (t1 == nullptr && t2 == nullptr) return true;
    if (t1 == nullptr || t2 == nullptr) return false;
    if (t1->val == t2->val) {
        return isSymmetricCore(t1->left, t2->right)
                && isSymmetricCore(t1->right, t2->left);
    }
    return false;
}