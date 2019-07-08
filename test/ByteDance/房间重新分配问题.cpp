#include <bits/stdc++.h>
using namespace std;

/*
 *  傻逼了，取余操作搞错了
 *  关键是确定房间i的位置，搞清楚想一个问题的目的是什么，或者做这道题
 *  缺了什么条件，带着目的去思考！！！
 */

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i ++ ) {
        cin >> a[i];
    }
    x--;
    // 找出房间i
    int roomI;
    int i = (x+1)%n, minn = INT_MAX;
    int cnt = n;
    while (cnt--) {
        if (a[i] <= minn) {
            roomI = i;
            minn = a[i];
        }
        i = (i+1)%n;
    }
    int p = a[roomI];
    
    for (int i = 0; i < n; i ++ ) {
        a[i] -= p;
    }

    i = x;
    while (i != roomI) {
        a[i]--;
        if (i == 0) i = n-1;
        else i--;
    }
    int offset;
    if (roomI <= x) offset = x-roomI;
    else offset = n-roomI+x;
    a[roomI] = n*p + offset;
    
    for (int i = 0; i < n; i ++ ) {
        cout << a[i] << " ";
    }
    return 0;
}