#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 判断一个链表中是否存在环
 *  Key: 设置两个指针，一个每次走一步，另一个一次走两步。
 *       若存在环，两个指针必定相遇，注意边界条件
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return false;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};