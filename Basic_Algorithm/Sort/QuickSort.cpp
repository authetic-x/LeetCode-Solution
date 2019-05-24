/*
 *  快速排序：也是分治算法，传说中的用的最多的排序算法
 *          快速排序最好的情况是每次选的pivot都可以
 *          将数组中分，则T(N) = N*log(N)
 *  选主元的方法：
 *  1. 用rand选一个随机数，但有开销
 *  2. 选头中尾三个数，取其中间大小的数
 *  
 *  最坏的情况是数组恰好有序，相当于每次partion后递归的数据量只减小了1
 *  没有利用分治的特点，时间复杂度会达到O(n*n)
 *  关键是写好partion函数，时间复杂度总是O(n)，练好自己熟悉的写法，
 *  快排可是要手撕的！！！
 */

int A[];

void GetPivot();

int partion(int l, int r) {
    // Performance优化
    GetPivot();
    int tmp = A[l];
    int i = l, j = r;
    while (i < j) {
        while (i < j && A[j] >= tmp) j--;
        if (i < j) A[i++] = A[j];
        while (i < j && A[i] < tmp) i++;
        if (i < j) A[j--] = A[i];
    }
    A[i] = tmp;
    return i;
}

void QuickSort(int l, int r) {
    if (l < r) {
       int pivot = partion(l, r);
       QuickSort(l, pivot-1);
       QuickSort(pivot+1, r);
    }
}