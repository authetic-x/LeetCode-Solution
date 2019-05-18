#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
 *  Info: 合并k个有序链表
 *  Key: 分治。这里抄袭luochuo同学的写法，这种递归的
 *       分治写法很有意思，但时间效率和空间效率都很低，
 *       可能是C++原因，用优先队列和分治时间复杂度都是
 *       O(N*logk)
 */

// 不是最优解
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 2) {
            return mergeTList(lists[0], lists[1]);
        } else if (lists.size() > 2) {
            vector<ListNode*> l1;
            vector<ListNode*> l2;
            int len = lists.size();
            for (int i = 0; i < len / 2; i ++ ) {
                l1.push_back(lists[i]);
            }
            for (int i = len/2; i < len; i ++ ) {
                l2.push_back(lists[i]);
            }
            return mergeTList(mergeKLists(l1), mergeKLists(l2));
        } else if (lists.size() == 1) {
            return lists[0];
        } else {
            return NULL;
        }
    }

    ListNode* mergeTList(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        ListNode* l;
        if (l1->val < l2->val) {
            l = new ListNode(l1->val);
            l->next = mergeTList(l1->next, l2);
        } else {
            l = new ListNode(l2->val);
            l->next = mergeTList(l1, l2->next);
        }
        return l;
    }
};