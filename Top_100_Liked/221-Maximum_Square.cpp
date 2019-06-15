#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        int dp[m+1][n+1] = {0};
        int maxL = 0;
        for (int i = 1; i <= m; i ++ ) {
            for (int j = 1; j <= n; j ++ ) {
                if (matrix[i-1][j-1] == '1') {
                    dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
                    maxL = max(maxL, dp[i][j]);
                }
            }
        }
        return maxL * maxL;
    }
};
/* 
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        int row = matrix.size();
        int col = matrix[0].size();
        int res = 0;
        for (int i = 0; i < row; i ++ ) {
            for (int j = 0; j < col; j ++ ) {
                int x = i, y = j;
                int xMax = 0, yMax = 0;
                while (y < col) {
                    if (matrix[i][y] == 1) {
                        y ++;
                    } else break;
                }
                if (y - j > 0) {
                    
                }
            }
        }
    }
};
*/