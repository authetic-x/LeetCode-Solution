#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 判断一个链表是否有环，并返回环的起始点
 *  Key: 同样设置一个快指针，一个慢指针，假设有环的情况下先找到
 *       第一个重合点，然后将其中一个结点置为头结点，并将两个结点
 *       以同样的速度遍历，第一个重合的结点便是环的起点。
 *       一个简单的数学问题，画图稍微推算一个就可以有一个效率翻倍
 *       的算法，当然还是来源于聪明的网友
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (fast == nullptr || fast->next == nullptr) return nullptr;
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
 
 // my first solution, low efficient
class Solution1 {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return nullptr;
        set<ListNode*> s;
        ListNode* detect = head;
        while (detect != nullptr) {
            if (s.find(detect) != s.end()) {
                return detect;
            }
            s.insert(detect);
            detect = detect->next;
        }
        return nullptr;
    }
};