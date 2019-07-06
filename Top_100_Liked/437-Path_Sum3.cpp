#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 求树的路径和，满足某个值的条数，只能向下走
 *  Key: 没想到暴力递归解法也能过，不过没有那么好写
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == nullptr) return 0;
        int ans = 0;
        core(root, 0, sum, ans);
        return ans + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

    void core(TreeNode* root, int cur, int sum, int &ans) {
        if (root == nullptr) return;
        cur = cur + root->val;
        if (cur == sum) {
            ans++;
        }
        core(root->left, cur, sum, ans);
        core(root->right, cur, sum, ans);
    }
};