#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 二叉树中序遍历
 *  Key: 基础算法，空间效率很低
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 不是最优解
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        Inorder(root, res);
        return res;
    }
    void Inorder(TreeNode* root, vector<int>& res) {
        if (root != NULL) {
            Inorder(root->right, res);
            res.push_back(root->val);
            Inorder(root->right, res);
        }
    }
};