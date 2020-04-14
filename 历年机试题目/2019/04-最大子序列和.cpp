#include "stdio.h"

int list[101];
int dp[101];

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; i ++ ) {
            scanf("%d", &list[i]);
        }
        for (int i = 0; i <= n; i ++ ) dp[i] = 0;

        int ans = 0;
        for (int i = 1; i <= n; i ++ ) {
            dp[i] = dp[i-1]+list[i] > list[i] ? dp[i-1]+list[i] : list[i];
            ans = max(dp[i], ans);
        }
        printf("%d\n", ans);
    }
    return 0;
}