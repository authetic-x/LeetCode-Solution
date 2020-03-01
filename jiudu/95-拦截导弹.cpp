#include "stdio.h"

/*
    最长递增子序列类问题
    思想：用dp数组保存以i结尾的最长序列，要求以K结尾的最长子序列
    只需遍历K之前的dp数组，若list[k]<=list[i]，则其子序列可以为dp[i]+1，
    每次循环取最大值即可
*/

int dp[26];
int list[26];

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i ++ ) {
            scanf("%d", &list[i]);
        }
        for (int i = 0; i < n; i ++ ) {
            int tmpMax = 1;
            for (int j = 0; j < i; j ++ ) {
                if (list[i] <= list[j]) {
                    tmpMax = max(tmpMax, dp[j] + 1);
                }
            }
            dp[i] = tmpMax;
        }
        int res = dp[0];
        for (int i = 1; i < n; i ++ ) {
            if (res < dp[i]) {
                res = dp[i];
            }
        }
        printf("%d\n", res);
    }
    return 0;
}