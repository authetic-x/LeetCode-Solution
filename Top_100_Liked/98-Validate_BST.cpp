#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 *  Info: 判断一个BST是不是合法的
 *  Key: luochuo学姐暴力的遍历一遍然后检查是不是增序序列
 *       效率上是一样的；不过我想写递归，但是写的有问题
 */

// 空间效率很低
class Solution {
private:
    vector<int> v;
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        Inorder(root);
        for (int i = 1; i < v.size(); i ++ ) {
            if (v[i] <= v[i-1]) return false;
        }
        return true;
    }
    void Inorder(TreeNode* root) {
        if (root != NULL) {
            Inorder(root->left);
            v.push_back(root->val);
            Inorder(root->right);
        }
    }
};

// wrong answer
class Solution1 {
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        if (root->left != NULL) {
            if (root->left->val > root->val) return false;
        }
        if (root->left != NULL) {
            if (root->right->val < root->val) return false;
        }
        return isValidBST(root->left) && isValidBST(root->right);
    }
};