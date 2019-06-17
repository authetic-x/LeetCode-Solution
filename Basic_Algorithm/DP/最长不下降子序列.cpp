#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 找到一个最长的不下降子序列，可以不连续
 *        用dp时间复杂度为O(n*n)，感觉和暴力没区别
 */

int MaxAcendSubsequence(vector<int> s) {
    if (s.size() == 0) return 0;
    int len = s.size();
    vector<int> dp(len, 1);
    dp[0] = 1;
    int res = dp[0];
    for (int i = 1; i < len; i ++ ) {
        for (int j = 0; j < i; j ++ ) {
            if (s[j] <= s[i]) {
                dp[i] = dp[i] < dp[j]+1 ? dp[j]+1 : dp[i];
            }
        }
        if (res < dp[i]) res = dp[i];
    }
    return res;
}