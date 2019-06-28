#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 在二叉树中进行house robbing
 *  Key: 基本思路和数组中的一样，不同的是直接递归会超时，
 *       采用后序遍历的思路，记录子树递归的结果，就可以避免
 *       重复递归！
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    int rob(TreeNode* root) {
        int l = 0, r = 0;
        return robCore(root, l, r);
    }

    int robCore(TreeNode* root, int &l, int &r) {
        if (root == nullptr) return 0;
        int ll = 0, lr = 0, rl = 0, rr = 0;
        l = robCore(root->left, ll, lr);
        r = robCore(root->right, rl, rr);
        return max(l+r, root->val+ll+lr+rl+rr);
    }
};