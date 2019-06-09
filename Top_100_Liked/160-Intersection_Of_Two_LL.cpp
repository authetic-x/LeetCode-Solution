#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 求两个链表的交叉结点
 *  key: 先求出两个链表的长度，将长链表与短链表对齐，再同时向后移动
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
  
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;
        int lenA = 0, lenB = 0;
        ListNode* p = headA;
        ListNode* q = headB;
        while (p != nullptr) {
            lenA++;
            p = p->next;
        }
        while (q != nullptr) {
            lenB++;
            q = q->next;
        }
        p = headA, q = headB;
        if (lenA > lenB) {
            int n = lenA - lenB;
            while (n) {
                p = p->next;
                n--;
            }
        } else if (lenA < lenB) {
            int n = lenB - lenA;
            while (n) {
                q = q->next;
                q--;
            }
        }
        while (p != nullptr) {
            if (p == q) return p;
            p = p->next;
            q = q->next;
        }
        return nullptr;
    }
};