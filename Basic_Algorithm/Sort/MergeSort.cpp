/*
 *  归并排序：都写烂了，典型的分治，
 *          先分开左右两边，将两边先排序好了再并起来
 *          时间复杂度为N*logN
 */


int n;

void Merge(int A[], int l1, int l2, int r1, int r2) {
    int tmp[n];
    int i = 0;
    while (l1 <= l2 && r1 <= r2) {
        if (A[l1] < A[r1]) tmp[i++] = A[l1++];
        else tmp[i++] = A[l2++];
    }
    while (l1 <= l2) tmp[i++] = A[l1++];
    while (r1 <= r2) tmp[i++] = A[r1++];
    for (int j = 0, k = l1; j < i; j ++, k ++) {
        A[k] = tmp[j];
    }
}

void MergeSort(int A[], int l, int r) {
    if (l < r) {
        int mid = (l+r) / 2;
        MergeSort(A, l, mid);
        MergeSort(A, mid+1, r);
        Merge(A, l, mid, mid+1, r);
    }
}