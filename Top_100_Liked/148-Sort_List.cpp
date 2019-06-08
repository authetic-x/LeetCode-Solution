#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 将一个链表排序
 *  Key: 这里用的是归并排序，唯一的技巧是如何获得中间的点，
 *       设置一个快指针和一个慢指针迭代即可
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* mid = getMid(head);
        ListNode* next = mid->next;
        mid->next = nullptr;
        return merge(sortList(head), sortList(next));
    }
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* left, ListNode* right) {
        if (left == nullptr) return right;
        if (right == nullptr) return left;
        if (left->val < right->val) {
            left->next = merge(left->next, right);
            return left;
        } else {
            right->next = merge(left, right->next);
            return right;
        }
    }
};