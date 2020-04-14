#include "stdio.h"
#include "stack"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

void preOrder(TreeNode *root) {
    stack<TreeNode*> st;
    TreeNode *p = root;
    while(!st.empty() || p != nullptr) {
        if (p) {
            printf("%d\n", p->val);
            p = p->left;
        } else {
            p = st.top();
            p = p->right;
            st.pop();
        }
    }
}

void inOrder(TreeNode* root) {
    stack<TreeNode*> st;
    TreeNode* p = root;
    while(!st.empty() || p) {
        if (p) {
            st.push(p);
            p = p->left;
        } else {
            p = st.top();
            st.pop();
            printf("%d\n", p->val);
            p = p->right;
        }
    }
}

void postOrder(TreeNode* root) {
    stack<TreeNode*> st;
    TreeNode *p = root, *lastNode = nullptr;
    while (!st.empty() || p) {
        if (p) {
            st.push(p);
            p = p->left;
        } else {
            p = st.top();
            if (p->right == lastNode || p->right == nullptr) {
                printf("%d\n", p->val);
                lastNode = p;
                st.pop();
                p = nullptr;
            } else {
                p = p->right;
            }
        }
    }
}