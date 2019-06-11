#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

void deleteNextNode(ListNode* &head, ListNode* node) {
    if (head == node) {
        ListNode* ptr = head;
        head = head->next;
        delete ptr;
        return;
    }
    if (node->next == nullptr) {
        ListNode* ptr = head;
        while (ptr->next != node) {
            ptr = ptr->next;
        }
        ptr->next = nullptr;
        delete node;
        return;
    }
    node->val = node->next->val;
    ListNode* ptr = node->next;
    node->next = node->next->next;
    delete ptr;
    return;
}

void deleteDuplicate(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return;
    ListNode* ptr = head;
    while (ptr != nullptr && ptr->next != nullptr) {
        while (ptr != nullptr && ptr->next != nullptr && 
                ptr->next->val == ptr->val) {
            ListNode* tmp = ptr->next;
            ptr->next = ptr->next->next;
            delete tmp;
        }
        ptr = ptr->next;
    }
}