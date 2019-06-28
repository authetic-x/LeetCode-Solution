#include <bits/stdc++.h>
using namespace std;

/*
 *  Key: 看是第几次碰到结点
 */

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

// 中序遍历
void InOrder(TreeNode* root) {
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while (cur != nullptr || !st.empty()) {
        while (cur != nullptr) {
            st.push(cur);
            cur = cur->left;
        }
        if (!st.empty()) {
            cur = st.top();
            printf("%d ", cur->val);
            cur = cur->right;
            st.pop();
        }
    }
}

// 先序遍历
void PreOrder(TreeNode* root) {
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while (cur != nullptr || !st.empty()) {
        while (cur != nullptr) {
            printf("%d ", cur->val);
            st.push(cur);
            cur = cur->left;
        }
        if (!st.empty()) {
            cur = st.top();
            st.pop();
            cur = cur->right;
        }
    }
}

// 后序遍历
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
                printf("%d ", cur->val);
                prePop = cur;
                st.pop();
            } else {
                cur = cur->right;
                break;
            }
        }
    }
}