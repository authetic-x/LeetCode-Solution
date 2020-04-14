struct LinkList {
    int val;
    LinkList* next;
};

LinkList* func(LinkList* head, int m) {
    if (head == nullptr) return nullptr;
    
    // 找到尾节点，赋值给p
    LinkList* q = head, *p;
    while (q->next != head) q = q->next;
    p = q, q = head;

    int cnt = 0;    
    // 头节点
    LinkList* root = nullptr, *x = root;
    while (q->next = q) {
        cnt++;
        if (cnt % m == 0) {
            x->next = q;
            x = x->next;

            p->next = p->next->next;
            q = p->next;
        } else {
            p = p->next;
            q = q->next;
        }
    }
    x->next = q;
    x->next->next = root->next;
    return root->next;
}