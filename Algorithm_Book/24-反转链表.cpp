#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

void reverseCore(ListNode* pre, ListNode* cur, ListNode* &root) {
    if (cur == nullptr) {
        root = pre;
        return;
    }
    reverse(cur, cur->next);
    cur->next = pre;
}

ListNode* reverseLinkedList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* root = new ListNode();
    reverseCore(nullptr, head, root);
    return root;
}