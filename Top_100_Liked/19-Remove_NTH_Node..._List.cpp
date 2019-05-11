#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
 *  Info: 给出一个链表，删除倒数第n个结点，返回头结点
 *  Key: 找出要删除结点的前一个结点即可，头结点特殊处理
 *       专业的做法是标记两个结点p,q指向头结点，先将p向
 *       后移动n个位置，再将p,q同时往后移，具体细节省略！
 */

// 先遍历得出链表长度，时间复杂度无差别
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode *tmp = head;
        while (tmp != NULL) {
            tmp = tmp->next;
            len++;
        }
        if (len - n == 0) {
            return head->next;
        }
        tmp = head;
        for (int i = 1; i < len-n; i ++ ) {
            tmp = tmp->next;
        }
        tmp->next = tmp->next->next;
        return head;
    }
};