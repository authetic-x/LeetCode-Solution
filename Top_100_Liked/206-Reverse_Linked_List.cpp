#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 反转链表
 *  Key: 递归
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* root;
        reverse(nullptr, head, root);
        return root;
    }
    void reverse(ListNode* pre, ListNode* node, ListNode* &head) {
        if (node == nullptr) {
            head = pre;
            return;
        }
        reverse(node, node->next, head);
        node->next = pre;
    }
};