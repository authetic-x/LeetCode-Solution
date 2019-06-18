#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next, *sibling;
    ListNode(int v) {val = v;}
};

/*
 *  Info: 复制复杂链表，该链表除了next结点外，还包含sibling指向任意一个结点或null
 *  Key: 方法1：设置哈希表，存储每个结点到复制结点的映射，这样就能快速找到复制结点的sibling
 *       方法2：复制每个结点时，将复制的结点放在原结点的后面，这样先复制出所有结点，
 *              然后复制结点的sibling就在原结点sibling的后一个位置，查找复杂度为O(1)
 */

ListNode* duplicate(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* pHead = head;
    while (pHead != nullptr) {
        ListNode* cloneNode = new ListNode(pHead->val);
        cloneNode->next = pHead->next;
        pHead->next = cloneNode;
        pHead = cloneNode->next;
    }
    pHead = head;
    while (pHead != nullptr) {
        if (pHead->sibling != nullptr) {
            pHead->next->sibling = pHead->sibling->next;
        }
    }
    ListNode* pClone = head->next;
    while (pClone->next != nullptr) {
        pClone->next = pClone->next->next;
        pClone = pClone->next;
    }
    return head->next;
}