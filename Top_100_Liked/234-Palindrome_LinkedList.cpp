#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// from wise net-coder
// 切，从运行效率来看，还不如我的bad solution，花里胡哨
// 递归和用栈存储空间上没什么区别，但时间上由于栈的返回会更慢
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        return check(head, head);
    }
    bool check(ListNode* &head, ListNode* p) {
        if (p == nullptr) return true;
        bool isPal = check(head, p->next);
        if (head->val != p->val) return false;
        head = head->next;
        return isPal;
    }
};
 
// my bad solution
class Solution1 {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;
        stack<int> st;
        ListNode* root = head;
        while (root != nullptr) {
            st.push(root->val);
            root = root->next;
        }
        while (head != nullptr) {
            if (head->val != st.top()) return false;
            st.pop();
            head = head->next;
        }
        return true;
    }
};