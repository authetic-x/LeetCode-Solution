#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 找到一颗二叉树的最长路径和，规定不用从根结点开始，但必须是一条连续路径
 *  Key: 典型的用递归解决子问题，设置maxValue保证最大值得到更新
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    int maxValue = INT_MIN;
    int maxPathSum(TreeNode* root) {
        if (root == nullptr) return 0;
        findMaxValue(root);
        return maxValue;
    }
    int findMaxValue(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = max(0, findMaxValue(root->left));
        int right = max(0, findMaxValue(root->right));
        maxValue = max(maxValue, left+right+root->val);
        return max(left, right)+root->val;
    }
};