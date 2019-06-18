#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

void LayerTraversal(TreeNode* root) {
    if (root == nullptr) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty) {
        int size = q.size();
        while (size--) {
            TreeNode* front = q.front();
            q.pop();
            printf("%d ", front->val);
            if (front->left != nullptr) q.push(front->left);
            if (front->right != nullptr) q.push(front->right);
        }
        printf("\n");
    }
}