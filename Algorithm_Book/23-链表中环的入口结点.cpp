#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

ListNode* entryNodeOfLoop(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return nullptr;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    if (slow != fast) return nullptr;
    while (head != fast) {
        head = head->next;
        fast = fast->next;
    }
    return head;
}