#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 将二叉树转换为链表
 *  Key: 一道很经典的题目，后续遍历，设置一个pre结点记录之前的结点
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* pre = nullptr;
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        flatten(root->right);
        flatten(root->left);
        root->right = pre;
        root->left = nullptr;
        pre = root;
    }
};