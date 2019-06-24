#include <bits/stdc++.h>
using namespace std;

int TraslateNum(int n) {
    string s = to_string(n);
    vector<int> dp(s.length()+1, 0);
    dp[s.length()] = 1;
    dp[s.length()-1] = 1;
    int ans = 1;
    for (int i = s.length()-2; i >= 0; i ++ ) {
        int p1 = s[i]-'0', p2 = s[i+1]-'0';
        int num = p1*10 + p2;
        if (num >= 10 && num <= 25) {
            dp[i] += dp[i+2];
        }
        dp[i] += dp[i+1];
        ans += dp[i];
    }
    return ans;
}