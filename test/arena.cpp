#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

void Inorder(TreeNode* root) {
    if (root == nullptr) return;
    stack<TreeNode*> st;
    st.push(root);
    TreeNode* cur = root->left;
    while (!st.empty()) {
        while (cur != nullptr) {
            st.push(cur);
            cur = cur->left;
        }
        if (!st.empty()) {
            cur = st.top();
            st.pop();
            printf("%d ", cur->val);
            cur = cur->right;
        }
    }
}

void PreOrder(TreeNode* root) {
    if (root == nullptr) return;
    stack<TreeNode*> st;
    st.push(root);
    printf("%d ", root->val);
    TreeNode* cur = root->left;
    while(!st.empty()) {
        while (cur != nullptr) {
            printf("%d ", cur->val);
            st.push(cur);
            cur = cur->left;
        }
        if(!st.empty()) {
            cur = st.top();
            st.pop();
            cur = cur->right;
        }
    }
}

void PostOrder(TreeNode* root) {
    stack<TreeNode*> st;
    TreeNode* cur = root;
    TreeNode* prePop = nullptr;
    while (cur != nullptr || !st.empty()) {
        while (cur != nullptr) {
            st.push(cur);
            cur = cur->left;
        }
        while (!st.empty()) {
            cur = st.top();
            if (cur->right == nullptr || cur->right == prePop) {
                st.pop();
                printf("%d ", cur->val);
                prePop = cur;
            } else {
                cur = cur->right;
                break;
            }
        }
    }
}