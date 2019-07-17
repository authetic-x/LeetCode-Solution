#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: dp, 二维矩阵每次向右或者向下走，每个格子有不同价值的礼物，
 *        求可获得的最大价值
 */

int MaxValue(vector<vector<int>> gift) {
    int m = gift.size();
    if (m == 0) return 0;
    int n = gift[0].size();
    vector<vector<int>> dp(m, vector<int>(n));
    for (int i = 0; i < m; i ++ ) {
        for (int j = 0; j < n; i ++ ) {
            if (i == 0 && j == 0) {
                dp[i][j] = gift[0][0];
            } else if (i == 0) {
                dp[i][j] = dp[i][j-1] + gift[i][j];
            } else if (j == 0) {
                dp[i][j] = dp[i-1][j] + gift[i][j];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + gift[i][j];
            }
        }
    }
    return dp[m-1][n-1];
}