#include <bits/stdc++.h>
using namespace std;

int BagPro01(vector<int> w, vector<int> c, int v) {
    vector<vector<int>> dp(w.size()+1, vector<int>(v+1, 0));
    for (int i = 1; i <= w.size(); i ++ ) {
        for (int j = w[i]; j <= v; j ++ ) {
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + c[i]);
        }
    }
    return dp[w.size()][v];
}

/*
 *  完全背包问题只是换一下状态转移方程：
 *  dp[i][v] = max(dp[i-1][v], dp[i][v-w[i]] + c[i])
 */