#include "stdio.h"

// AC

long long list[100001];
int dp_pre[100001];
int dp_post[100001];

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i ++ ) {
            scanf("%d", &list[i]);
        }
        dp_pre[n - 1] = 1;
        dp_post[0] = 1;
        for (int i = n - 2; i >= 0; i -- ) {
            if (list[i] < list[i+1]) {
                dp_pre[i] = dp_pre[i + 1] + 1;
            } else {
                dp_pre[i] = 1;
            }
        }
        for (int i = 1; i < n; i ++ ) {
            if (list[i] > list[i-1]) {
                dp_post[i] = dp_post[i - 1] + 1;
            } else {
                dp_post[i] = 1;
            }
        }
        int ans = 1;
        for (int i = 0; i < n; i ++ ) {
            if (i == 0) {
                ans = dp_pre[i + 1]+1;
            } else if (i == n-1) {
                ans = max(ans, dp_post[i - 1]+1);
            } else if (list[i-1] + 1 < list[i+1]) {
                ans = max(ans, dp_pre[i + 1] + dp_post[i - 1]+1);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}