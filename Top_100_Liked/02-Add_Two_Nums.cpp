#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
    Info: 两个非0整数用链表倒序存储，要求将两个数相加并用链表输出
    Key： 目前不是最优解！
*/
 
class Solution1 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode(0);
        stack<int> st;
        queue<int> q;
        // num表示两数之和，p2表示进位
        int num = 0, p1 = 0, p2 = 0;
        while (l1 != NULL && l2 != NULL) {
            p1 = l1->val + l2->val;
            l1 = l1->next, l2 = l2->next;
            q.push((p1 + p2)%10);
            p2 = (p1+p2)/10;
        }
        while (l1 != NULL) {
            int val = l1->val + p2;
            q.push(val % 10);
            p2 = val / 10;
            l1 = l1->next;
        }
        while (l2 != NULL) {
            int val = l2->val + p2;
            q.push(val % 10);
            p2 = val / 10;
            l2 = l2->next;
        }
        if (p2 != 0) {
            q.push(p2);
        }
        l3->val = q.front();
        q.pop();
        ListNode* tmp = l3;
        while (!q.empty()) {
            ListNode* node = new ListNode(q.front());
            q.pop();
            tmp->next = node;
            tmp = tmp->next;
        }
        return l3;
    }
};

// 稍微优化了以下，不用栈和队列，但代码好像没有少多少～
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode(0);
        // num表示两数之和，p2表示进位
        int num = 0, p1 = 0, p2 = 0;
        ListNode* tmp = l3;
        while (l1 != NULL && l2 != NULL) {
            p1 = l1->val + l2->val;
            l1 = l1->next, l2 = l2->next;
            ListNode* node = new ListNode((p1+p2)%10);
            tmp->next = node;
            tmp = tmp->next;
            p2 = (p1+p2)/10;
        }
        while (l1 != NULL) {
            int val = l1->val + p2;
            ListNode* node = new ListNode(val%10);
            tmp->next = node;
            tmp = tmp->next;
            p2 = val / 10;
            l1 = l1->next;
        }
        while (l2 != NULL) {
            int val = l2->val + p2;
            ListNode* node = new ListNode(val%10);
            tmp->next = node;
            tmp = tmp->next;
            p2 = val / 10;
            l2 = l2->next;
        }
        if (p2 != 0) {
            ListNode* node = new ListNode(p2);
            tmp->next = node;
            tmp = tmp->next;
        }
        return l3->next;
    }
};