#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 二叉树的层次遍历，要求存储时区分不同层
 *  Key： 用size事先记住每层大小即可！
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (root == NULL) return res;
        q.push(root);
        TreeNode* node;
        while(!q.empty()) {
            int size = q.size();
            vector<int> tmp;
            while (size--) {
                node = q.front();
                q.pop();
                tmp.push_back(node->val);
                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};