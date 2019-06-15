#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

ListNode* findLastKNode(ListNode* head, int k) {
    if (head == nullptr || k <= 0) return nullptr;
    ListNode* tmp = head;
    for (int i = 0; i < k; i ++ ) {
        if (tmp->next != nullptr) {
            tmp = tmp->next;
        } else {
            return nullptr;
        }
    }
    while (tmp != nullptr) {
        head = head->next;
        tmp = tmp->next;
    }
    return head;
}