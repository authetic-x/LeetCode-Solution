#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 简单题，求树的最大深度，即层次
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        return max(maxDepth(root->left)+1, maxDepth(root->right)+1);
    }
};