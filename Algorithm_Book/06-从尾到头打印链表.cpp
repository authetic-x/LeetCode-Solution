#include <bits/stdc++.h>
using namespace std;

struct LinkedList {
    int val;
    LinkedList* next;
}

void PrintList(ListedList* root) {
    if (root == nullptr) return;
    stack<int> st;
    LinkedList* head = root;
    while (head != nullptr) {
        st.push(head->val);
        head = head->next;
    }
    while (!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }
}

void PrintList_Recursive(LinkedList* root) {
    if (root == nullptr) return;
    PrintList_Recursive(root->next);
    cout << root->val << endl;
}