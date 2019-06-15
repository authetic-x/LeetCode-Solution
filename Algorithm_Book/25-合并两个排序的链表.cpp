#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

ListNode* mergeTwoLL(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;
    ListNode* pHead = nullptr;
    if (l1->val <= l2->val) {
        pHead = l1;
        pHead->next = mergeTwoLL(l1->next, l2);
    } else {
        pHead = l2;
        pHead->next = mergeTwoLL(l1, l2->next);
    }
    return pHead;
}