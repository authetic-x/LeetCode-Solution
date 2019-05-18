#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 给出一个m*n的方格，机器人左上方开始，每次只能向右
 *        或者向下移动一个位置，问到达右下角终点的路径有多少条
 *  Key: DP。i = 0 或者 j = 0时可能的路径只有一条，位于其它位置
 *       时该点路径为左方格和上方格可能路径之和
 */

class Solution {
public:
    int uniquePaths(int m, int n) {
        int a[100][100];
        for (int i = 0; i < m; i ++ ) {
            for (int j = 0; j < n; j ++ ) {
                if (i == 0 || j == 0) {
                    a[i][j] = 1;
                } else {
                    a[i][j] = a[i-1][j] + a[i][j-1];
                }
            }
        }
        return a[m-1][n-1];
    }
};