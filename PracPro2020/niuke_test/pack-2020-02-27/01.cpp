#include "stdio.h"

// AC 80%

long long a[100001];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i ++ ) {
            scanf("%d", &a[i]);
        }
        int ans = 0;
        // true表示递增子序列，false表示递减
        bool flag = true;
        for (int i = 1; i < n; i ++ ) {
            if (flag) {
                if (a[i] < a[i-1]) {
                    flag = !flag;
                    ans++;
                }
            } else {
                if (a[i] > a[i-1]) {
                    flag = !flag;
                    ans++;
                }
            }
        }
        /* if (flag && a[n-1] >= a[n-2] || !flag && a[n-1] <= a[n-2]) {
            ans += 1;
        } else {
            ans += 2;
        } */
        ans++;
        printf("%d\n", ans);
    }
}