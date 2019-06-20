#include <bits/stdc++.h>
using namespace std;

int MaxSubsequenceSum01(vector<int> s) {
    if (s.size() == 0) return 0;
    int ans = 0, cur = 0;
    for (auto num : s) {
        if (cur <= 0) cur = num;
        else cur += num;
        ans = max(ans, cur);
    }
    return ans;
}

int MaxSubsequenceSum02(vector<int> s) {
    if (s.size() == 0) return 0;
    vector<int> dp(s.size());
    dp[0] = s[0];
    int res = dp[0];
    for (int i = 1; i < s.size(); i ++ ) {
        dp[i] = max(s[i], dp[i-1]+s[i]);
        res = max(res, dp[i]);
    }
    return res;
}