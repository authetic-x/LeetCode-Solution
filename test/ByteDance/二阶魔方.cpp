#include <bits/stdc++.h>
using namespace std;

// op1 一次转两格
int op1[6][8] = {
    {0,2,6,12,16,18,20,22},
    {1,3,7,13,17,19,21,23},
    {4,5,6,7,8,9,23,22},
    {10,11,12,13,14,15,21,20},
    {2,3,8,14,17,16,11,5},
    {9,15,19,18,10,4,0,1}
};
// op2一次转一格
int op2[6][4] = {
    {4,5,11,10},
    {8,14,15,9},
    {0,2,3,1},
    {16,17,19,18},
    {6,7,13,12},
    {22,23,21,20}
};

void op(int a[], int offset, int n) {
    vector<int> tmp(n);
    for (int i = 0; i < n; i ++ ) tmp[i] = a[i];
    for (int i = 0; i < n; i ++ ) {
        int j = (i+offset)%n;
        a[j] = tmp[i];
    }
}

vector<int> num(24);

void recursiv1(int a[], int cnt) {
    if (cnt == 5) return;

    for (int i = 0; i < 6; i ++ ) {
        op(op1[i], 2, 8);
        recursiv1(cnt+1);
    }
}

int main() {
    for (int i = 0; i < 24; i ++ ) {
        int tmp;
        cin >> tmp;
        num[i] = tmp;
    }
    vector<int> tmp(24);
    for (int i = 0; i < 24; i ++ ) tmp[i] = num[i];
    
}