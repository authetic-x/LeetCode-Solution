#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: dp, 125343这种数字翻译为字符串有多少种方式，比如12，可以翻译为
 *        ab或者12对应的那个字母
 */

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
    }
    return dp[0];
}