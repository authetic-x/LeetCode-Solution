struct Tree {
    int val;
    Tree* lchild;
    Tree* rchild;
    Tree(int val): val(val), lchild(nullptr), rchild(nullptr) {}
};

// 构建二叉树，C++写太麻烦了。后期用Go改进一下
Tree* ConstructTree(int* preOrder, int* inOrder, int n) {
    if (preOrder == nullptr || inOrder == nullptr || n <= 0) {
        return nullptr;
    }
    int root_val = preOrder[0];
    // 根结点在中序遍历中的位置
    int k;
    for (int i = 0; i < n; i ++ ) {
        if (inOrder[i] == root_val) {
            k = i;
            break;
        }
    }
    Tree* root = new Tree(root_val);
    //root->lchild = ConstructTree(preOrder+1)
}