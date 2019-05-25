#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 *  Info: 判断一颗树是否对称
 *  Key: 如果一棵树对称，它的镜像是本身，
 *       如果两棵树互为镜像，它们根节点相等
 *       且树1的右子树与树2的左子书互为镜像
 *       树1的左子树与树2的右子书互为镜像
 */

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }

    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL && t2 == NULL) return true;
        if (t1 == NULL || t2 == NULL) return false;
        return (t1->val == t2->val) 
                && isMirror(t1->right, t2->left) 
                && isMirror(t1->left, t2->right);
    }
};