#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
 *  简单题，注意细节！
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode(0);
        ListNode* tmp = l3;
        while (l1 != NULL && l2 != NULL) {
            ListNode *node = new ListNode(0);
            if (l1->val < l2->val) {
                node->val = l1->val;
                l1 = l1->next;
            } else {
                node->val = l2->val;
                l2 = l2->next;
            }
            tmp->next = node;
            tmp = tmp->next;
        }
        while (l1 != NULL) {
            ListNode* node = new ListNode(l1->val);
            l1 = l1->next;
            tmp->next = node;
            tmp = tmp->next;
        }
        while (l2 != NULL) {
            ListNode* node = new ListNode(l2->val);
            l2 = l2->next;
            tmp->next = node;
            tmp = tmp->next;
        }
        return l3->next;
    }
};