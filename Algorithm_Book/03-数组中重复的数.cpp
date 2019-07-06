#include <bits/stdc++.h>
using namespace std;

int duplicate(int a[], int n) {
    if (a == nullptr || n <= 0) return -1;
    for (int i = 0; i < n; i ++ ) {
        if (a[i] < 0 || a[i] > n-1) {
            return -1;
        }
    }
    for (int i = 0; i < n; i ++ ) {
        while (a[i] != i) {
            if (a[a[i]] == a[i]) {
                return a[i];
            } 
            swap(a[i], a[a[i]]);
        }
    }
    return -1;
}