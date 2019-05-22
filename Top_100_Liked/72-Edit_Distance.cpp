#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 通过增加，删除，替换，求将一个单词转换为另一个单词的最小步数
 *  Key: DP问题，注意dp数组的下标，代表的是第几个！
 */

// 空间效率没有达到最优，可以只用一维数组
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        int dp[m+1][n+1];
        for (int i = 0; i <= m; i ++ ) {
            dp[i][0] = i;
        }
        for (int i = 1; i <= n; i ++ ) {
            dp[0][i] = i;
        }
        for (int i = 1; i <= m; i ++ ) {
            for (int j = 1; j <= n; j ++ ) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                }
            }
        }
        return dp[m][n];
    }
};