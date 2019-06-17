#include <bits/stdc++.h>
using namespace std;

// 最长回文子串
int MaxPalindrome(string s) {
    if (s.length() == 0) return 0;
    int len = s.length();
    vector<vector<int>> dp(len, vector<int>(len, 0));
    int ans = 1;
    for (int i = 0; i < len; i ++ ) {
        dp[i][i] = 1;
        if (i < len-1) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = 1;
                ans = 2;
            }
        }
    }
    for (int L = 3; L <= len; L ++ ) {
        for (int i = 0; i+L-1 < len; i ++ ) {
            int j = i+L-1;
            if (s[i] == s[j] && dp[i+1][j-1] == 1) {
                dp[i][j] = 1;
                ans = L;
            }
        }
    }
    return ans;
}