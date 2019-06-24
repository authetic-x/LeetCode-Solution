#include <bits/stdc++.h>
using namespace std;

struct LinkNode {
    int val;
    LinkNode* next;
};

LinkNode* CommonNode(LinkNode* l1, LinkNode* l2) {
    if (l1 == nullptr || l2 == nullptr) return nullptr;

    int len1 = 0, len2 = 0;
    LinkNode* tmp = l1;
    while (tmp != nullptr) {
        tmp = tmp->next;
        len1++;
    }
    tmp = l2;
    while (tmp != nullptr) {
        tmp = tmp->next;
        len2++;
    }
    if (len1 > len2) {
        int i = len1-len2;
        while (i--) {
            l1 = l1->next;
        }
    } else {
        int i = len2-len1;
        while (i--) {
            l2 = l2->next;
        }
    }
    while (l1 != nullptr) {
        if (l1 == l2) break;
        l1 = l1->next;
        l2 = l2->next;
    }
    return l1;
}