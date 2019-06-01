
struct Tree {
    int val;
    Tree* lchild;
    Tree* rchild;
    Tree* parent;
    Tree(int val): val(val), lchild(nullptr), rchild(nullptr), 
                    parent(nullptr) {}
};

// 按中序遍历的顺序找到一个结点的下一个结点
// 当该结点有右子树的时候，遍历到右子树的最左结点即可
// 当该结点是父结点的左子结点时，父结点就是下一结点
// 如果该结点是父节点的右子节点有没有右子树，向上遍历，
// 找到一个结点是其父节点的左子节点的情况，该父节点就是下一个结点
Tree* GetNext(Tree* node) {
    if (node == nullptr) return nullptr;
    Tree* next_node = nullptr;
    if (node->rchild != nullptr) {
        node = node->rchild;
        while (node->lchild != nullptr) {
            node = node->lchild;
        }
        node = next_node;
    } else if (node->parent != nullptr) {
        Tree* current = node;
        Tree* parent = node->parent;
        while (parent->lchild != current && parent != nullptr) {
            current = parent;
            parent = parent->parent;
        }
        next_node = parent;
    }
    return next_node;
}