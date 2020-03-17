#include "stdio.h"

/*
    错排公式：f(n) = (n-1)*f(n-1) + (n-1)f(n-2)
    推理过程有些麻烦，先记住！
*/

long long dp[21];

int main() {
    int n;
    dp[2] = 1;
    for (int i = 3; i <= 20; i ++ ) {
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
    }
    while (scanf("%d", &n) != EOF) {
        printf("%lld\n", dp[n]);
    }
    return 0;
}