#include "iostream"
using namespace std;

int partion(int a[], int l, int r) {
    int tmp = a[l];
    int i = l;
    int j = r;
    while (i < j) {
        while (a[j] >= tmp && i < j)
            j--;
        if (i < j)
            a[i] = a[j];
        while (a[i] < tmp && i < j)
            i++;
        if (i <= j)
            a[j] = a[i];
    }
    a[i] = tmp;
    return i;
}

void QuickSort(int a[], int l, int r) {
    if (l < r) {
        int mid = partion(a, l, r);
        QuickSort(a, l, mid - 1);
        QuickSort(a, mid + 1, r);
    }
}

int main() {
    int a[5] = {45, 12, 34, 23, 10};

    QuickSort(a, 0, 4);
    for (int i = 0; i < 5; i ++ ) {
        cout << a[i] << endl;
    }
}