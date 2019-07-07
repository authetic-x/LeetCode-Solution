#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 找出一颗二叉树能形成的最长路径，与求最大路径值那道题差不多
 *  Key: 全局变量记录最大值，递归函数返回左子树和右子树中路径更长的一个
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
private:
    int maxNode = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        maxNodes(root);
        return maxNode-1;
    }

    int maxNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int l = maxNodes(root->left);
        int r = maxNodes(root->right);
        maxNode = max(maxNode, l+r+1);
        return max(l, r)+1;
    }
};