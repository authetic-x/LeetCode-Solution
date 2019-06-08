#include <bits/stdc++.h>
using namespace std;

// DP Solution
int maxLength(int n) {
    if (n <= 0) return 0;
    int dp[n+1];
    for (int i = 0; i <= n; i ++ ) {
        dp[i] = i;
    }
    for (int i = 3; i <= n; i ++ ) {
        for (int j = 1; j <= i/2; j ++ ) {
            dp[i] = max(dp[i], dp[j]*dp[i-j]);
        }
    }
    return dp[n];
}

// Greedy Solution
int maxLen(int n) {
    if (n <= 0) return 0;
    if (n <= 2) return n;
    int timeOf3 = n / 3;
    if (n - 3*timeOf3 == 1) {
        timeOf3 -= 1;
    }
    int timeOf2 = (n - 3*timeOf3) / 2;
    return (int)(pow(3, timeOf3)) * (int)(pow(2, timeOf2));
}