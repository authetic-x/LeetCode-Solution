#include <bits/stdc++.h>
using namespace std;

/*
    Cm/n = n! / m!*(n-m)!
 */

// 计算阶乘 C 2/m

const int maxn = 1000005;

int a[maxn];

long long calculate(long long n) {
    return (n-1) * n / 2;
}

int main() {
    int n, d;
    cin >> n >> d;
    if (n <= 2) {
        cout << 0 << endl;
        return 0;
    }
    cin >> a[0] >> a[1];
    long long res = 0;
    for (int i = 0, j = 2; j < n; j ++ ) {
        cin >> a[j];
        while (a[j] - a[i] > d) {
            i ++;
        }
        res += calculate(j-i);
    }
    cout << res % 99997867 << endl;
    return 0;
}