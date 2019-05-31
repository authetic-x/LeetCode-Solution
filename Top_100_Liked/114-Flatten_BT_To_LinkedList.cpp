#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 将二叉树转换为链表
 *  Key: 一道很经典的题目，暂时还不知道怎么做
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// wrong answer
class Solution {
public:
    TreeNode* tmp;
    void flatten(TreeNode* root) {
        TreeNode* head = new TreeNode(0);
        tmp = head;
        preOrder(root);
        return head->right;
    }
    void preOrder(TreeNode* root) {
        if (root == NULL) return;
        TreeNode* newNode = new TreeNode(root->val);
        tmp->right = newNode;
        tmp = tmp->right;
        preOrder(root->left);
        preOrder(root->right);
    }
};