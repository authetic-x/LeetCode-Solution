/*
 *  堆排序：相当于升级版的选择排序
 *  选择排序的做法是每次从未排序的序列中找一个最小数，
 *  将其插入到已排序序列的末尾，所以时间复杂度为O(n*n)
 *  如何使用最小堆的话，可以将找最小数的时间复杂度减小为logN,
 *  总体的时间复杂度就变为了N*logN
 */

void BuildHeap(int A[]);

int DeleteMin();

void HeapSort(int A[]) {
    BuildHeap(A);
    for (int i = 0; i < 10; i ++ ) {
        A[i] = DeleteMin();
    }
}