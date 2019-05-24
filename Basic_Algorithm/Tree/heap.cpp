/*
 *  可以用堆来实现优先队列
 *  堆的存储结构为完全二叉树
 * 
 *  堆的建立：
 *  1. 依次插入，时间复杂度为N*logN
 *  2. 先将所有的数依次插入到数组中，然后从最后一个数的
 *     父结点开始，依次将子树调整为堆，可以将时间复杂度减为O(N),
 *     即所有结点的高度之和，注意叶子结点的高度是0！
 */

#include <stdlib.h>

struct HeapStruct {
    int* Elements;
    int Size;
    int Capacity;
};

typedef HeapStruct* MaxHeap;

MaxHeap Create(int MaxSize) {
    MaxHeap H = (MaxHeap)malloc(sizeof(struct HeapStruct));
    H->Elements = (int*)malloc(sizeof(int)*(MaxSize+1));
    H->Capacity = 0;
    // INT_MAX 哨兵
    H->Elements[0] = 1000000;
    return H;
}

// T(N) = O(logN)
// 先将值插到数组末尾，然后依次与父结点比较，交换位置
void Insert(MaxHeap H, int item) {
    // Checking is the Heap full?
    int i = ++H->Size;
    // 当i为0时，循环一定会跳出，哨兵的作用
    for (; H->Elements[i/2] < item; i/2) {
        H->Elements[i] = H->Elements[i/2];
    }
    H->Elements[i] = item;
}

// 相当于先将最后一个数移到堆顶，然后向下翻转
// 判断当前结点有没有子结点，在子结点中找个大的比较，
// 不满足条件就继续向下翻，否则退出循环
// T(N) = O(logN)
int Delete(MaxHeap H) {
    // Checking is the Heap full?
    int MaxItem = H->Elements[1];
    int tmp = H->Elements[H->Size--];
    int parent, child;
    for (parent = 1; parent*2 <= H->Size; parent = child) {
        child = parent*2;
        if (child != H->Size) {
            if (H->Elements[child] < H->Elements[child+1]) {
                child++;
            }
        }
        if (H->Elements[child] <= tmp) break;
        else H->Elements[parent] = H->Elements[child];
    }
    H->Elements[parent] = tmp;
    return MaxItem;
}