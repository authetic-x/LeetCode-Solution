#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 将二叉搜索树中的每个结点的值加上树中比它大的所有结点值之和
 *  Key: 中序遍历，用一个变量记录即可
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
private:
    int sum = 0;
public:
    TreeNode* convertBST(TreeNode* root) {
        if (root == nullptr) return root;
        convertBST(root->right);
        sum += root->val;
        root->val = sum;
        convertBST(root->left);
        return root;
    }
};

class Solution2 {
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        TreeNode* node = root;
        stack<TreeNode*> st;
        while (!st.empty || node != nullptr) {
            while (node != nullptr) {
                st.push(node);
                node = node->right;
            }

            node = st.top();
            st.pop();
            sum += node->val;
            node->val = sum;
            node = node->left;
        }
    }
};