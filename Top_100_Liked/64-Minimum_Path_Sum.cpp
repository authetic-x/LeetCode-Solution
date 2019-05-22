#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 给出一个m*n网格，求从左上方走到右下方的最小路径和
 *  Key: 简单DP，和机器人问题(62-Unique Paths)类似
 */

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int dp[row][col];
        dp[0][0] = grid[0][0];
        for (int i = 0; i < row; i ++ ) {
            for (int j = 0; j < col; j ++ ) {
                if (i == 0 && j == 0) continue;
                if (i == 0) {
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                } else if (j == 0) {
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                } else {
                    dp[i][j] = min(dp[i-1][j]+grid[i][j], dp[i][j-1]+grid[i][j]);
                }
            }
        }
        return dp[row-1][col-1];
    }
};