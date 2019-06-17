#include <bits/stdc++.h>
using namespace std;

int MaxSumOfSubsequence(vector<int> s) {
    if (s.size() == 0) return 0;
    int len = s.size();
    vector<int> dp(len);
    dp[0] = s[0];
    int res = dp[0];
    for (int i = 1; i < len; i ++ ) {
        dp[i] = max(s[i], dp[i-1]+s[i]);
        if (res < dp[i]) dp[i] = res;
    }
    return res;
}