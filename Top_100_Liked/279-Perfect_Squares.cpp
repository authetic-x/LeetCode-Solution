#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 给出一个整数，求该数最少可由多少个可开方的数组成
 *  Key: DP，dp[i]代表整数i的最小组成数，注意是加1还是加2
 */

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1);
        dp[1] = 1;
        for (int i = 2; i <= n; i ++ ) {
            int tmp = INT_MAX;
            for (int j = 1; j*j <= n; j ++ ) {
                if (j*j == i) {
                    tmp = 1;
                    break;
                }
                tmp = min(tmp, dp[i-j*j]+1);
            }
            dp[i] = tmp;
        }
        return dp[n];
    }
};