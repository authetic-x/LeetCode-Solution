#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 给出一个二维数组，判断有多少组“连在”一起的1
 *  key: 深度遍历
 */

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; i ++ ) {
            for (int j = 0; j < n; j ++ ) {
                if (grid[i][j] == '1') {
                    count ++;
                    dfs(grid, i, j, m, n);
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n|| grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs(grid, i-1, j, m, n);
        dfs(grid, i+1, j, m, n);
        dfs(grid, i, j-1, m, n);
        dfs(grid, i, j+1, m, n);
    }
};