#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 求字符串中回文子串的个数
 *  Key: DP，不过效率很低
 */

class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));
        int ans = 0;
        for (int i = 0; i < s.length(); i ++ ) {
            dp[i][i] = 1;
            ans++;
            if (i+1 < s.length() && s[i] == s[i+1]) {
                dp[i][i+1] = 1;
                ans++;
            }
        }
        for (int len = 3; len <= s.length(); len ++ ) {
            for (int i = 0; i+len-1 < s.length(); i ++ ) {
                int j = i+len-1;
                if (dp[i+1][j-1] == 1 && s[i] == s[j]) {
                    dp[i][j] = 1;
                    ans++;
                }
            }
        }
        return ans;
    }
};