#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

// 后序遍历

bool isBalanced(TreeNode* root) {
    int depth = 0;
    return Core(root, depth);
}

bool Core(TreeNode* root, int &depth) {
    if (root == nullptr) return true;
    int lDepth = 0, rDepth = 0;
    if (Core(root->left, lDepth) && Core(root->right, rDepth)) {
        int diff = lDepth - rDepth;
        if (diff <= 1 && diff >= -1) {
            depth = diff;
            return true;
        }
    }
    return false;
}