#include <bits/stdc++.h>
using namespace std;

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
        findMaxSum(root);
        return maxValue;
    }
    int findMaxSum(TreeNode* root) {
        if (root == nullptr ) return 0;
        int left = max(0, findMaxSum(root->left));
        int right = max(0, findMaxSum(root->right));
        maxValue = max(maxValue, left+right+root->val);
        return root->val + max(left, right);
    }
};