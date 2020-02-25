#include "stdlib.h"
#include "stdio.h"

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// n为数组长度减一
void createHeap(int a[], int n) {
    int i = n / 2;
    while (i >= 0) {
        int j = i;
        // 向下翻转构造堆
        while (j*2 <= n) {
            int k = j * 2;
            if (k+1 <= n && a[k] > a[k+1]) {
                k += 1;
            }
            if (a[j] > a[k]) {
                swap(a[j], a[k]);
            }
            j = k;
        }
        i--;
    }
}
int deleteTop(int a[], int n) {
    int res = a[0];
    a[0] = a[n];
    int i = 0;
    while (i * 2 < n) {
        int j = i * 2;
        if (j+1 < n && a[j] > a[j+1]) {
            j += 1;
        }
        if (a[i] > a[j]) {
            swap(a[i], a[j]);
            i = j;
        } else {
            break;
        }
    }
    return res;
}

void HeapSort(int a[], int n) {
    createHeap(a, n);
    int len = n;
    while (len >= 0) {
        int tmp = deleteTop(a, len);
        a[len] = tmp;
        len--;
    }
    int i = 0, j = n;
    while (i <= j) {
        swap(a[i++], a[j--]);
    }
}

int main() {
    int a[5] = {23, 12, 32, 8, 10};
    HeapSort(a, 4);
    for (int i = 0; i <= 4; i ++ ) {
        printf("%d ", a[i]);
    }
}