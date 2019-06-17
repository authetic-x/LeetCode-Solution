#include <bits/stdc++.h>
using namespace std;

// 子序列可以不连续
// Longest Common Subsequence
int LCS(string a, string b) {
    if (a.length() == 0 || b.length() == 0) return 0;
    int lenA = a.length(), lenB = b.length();
    vector<vector<int>> dp(lenA, vector<int>(lenB));
    for (int j = 0; j < lenB; j ++ ) {
        if (a[0] == b[j]) dp[0][j] = 1;
        else dp[0][j] = 0;
        if (a[j] == b[0]) dp[j][0] = 1;
        else dp[j][0] = 0;
    }
    
    for (int i = 1; i < lenA; i ++ ) {
        for (int j = 1; j < lenB; j ++ ) {
            if (a[i] == a[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
}