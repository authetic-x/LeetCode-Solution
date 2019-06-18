#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

// 从根结点到叶结点形成一条路径
// 简单的回溯

vector<vector<TreeNode*>> ans;

vector<vector<TreeNode*>> findPath(TreeNode* root, int k) {
    if (root == nullptr) return ans;
    vector<TreeNode*> tmp;
    Core(root, tmp, 0, k);
    return ans;
}

// 注意何时pop_back
void Core(TreeNode* root, vector<TreeNode*> &tmp, int cur, int k) {
    if (root->left == nullptr && root->right == nullptr) {
        if (cur == k) ans.push_back(tmp);
    }
    if (root->left != nullptr) {
        tmp.push_back(root->left);
        Core(root->left, tmp, cur+root->left->val, k);
    }
    if (root->right != nullptr) {
        tmp.push_back(root->left);
        Core(root->left, tmp, cur+root->left->val, k);
    }
    tmp.pop_back();
}