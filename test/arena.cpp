#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void Swap(int a[], int left, int right) {
    int mid = (left+right) / 2;
    if (a[left] < a[mid]) {
        if (a[mid] < a[right]) {
            swap(a[left], a[mid]);
        } else if (a[left] < a[right]) {
            swap(a[left], a[right]);
        }
    } else {
        if (a[left] > a[right]) {
            if (a[mid] < a[right]) {
                swap(a[left], a[right]);
            } else {
                swap(a[left], a[mid]);
            }
        }
    }
}

int partion(int a[], int left, int right) {
    Swap(a, left, right);
    int tmp = a[left];
    int i = left, j = right;
    while (i < j) {
        while (i < j && a[j] >= tmp) j --;
        if (i < j) a[i] = a[j];
        while (i < j && a[i] <= tmp) i ++;
        if (i < j) a[j] = a[i];
    }
    a[i] = tmp;
    return i;
}

void QuickSort(int a[], int left, int right) {
    if (left < right) {
        int pivot = partion(a, left, right);
        QuickSort(a, left, pivot-1);
        QuickSort(a, pivot+1, right);
    }
}