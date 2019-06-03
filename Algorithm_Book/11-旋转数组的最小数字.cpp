
// 二分查找的关键是依据mid的值减小查找的范围
// 这道题处理一下三点值相等的情况即可
int Min(int a[], int n) {
    if (a == nullptr || n <= 0) return -1;
    if (n == 1) return a[0];
    int index1 = 0, index2 = n-1;
    int midIndex = 0;
    while (a[index1] >= a[index2]) {
        if (index2-index1 == 1) return a[index2];
        midIndex = (index1+index2)/2;
        if (a[index1] == a[index2] && a[index1] == a[midIndex]) {
            return FindMin(a, index1, index2);
        }
        if (a[midIndex] >= a[index1]) {
            index1 = midIndex;
        } else {
            index2 = midIndex;
        }
    }
    return a[midIndex];
}

int FindMin(int a[], int l, int r) {
    int res = a[l];
    for (int i = l+1; l <= r; l ++ ) {
        if (res > a[i]) {
            res = a[i];
        }
    }
    return res;
}