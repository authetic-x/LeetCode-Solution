#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 将一颗翻过来
 *  Key: 后序遍历
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;
        reverse(root);
        return root;
    }
    void reverse(TreeNode* root) {
        if (root == nullptr) return;
        reverse(root->left);
        reverse(root->right);
        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = tmp;
    }
};