#include "stdio.h"
#include "string.h"

/*
    最长公共子序列类问题
    思想：dp[i][j] = str1[i]==str2[j] ? dp[i-1][j-1]+1 : 
                                        max(dp[i-1][j], dp[i][j-1])
    注意细节！
*/

int dp[101][101];

int main() {
    char str1[101], str2[101];
    while (scanf("%s%s", str1, str2) != EOF) {
        int L1 = strlen(str1);
        int L2 = strlen(str2);
        for (int i = 1; i <= L1; i++) {
            for (int j = 1; j <= L2; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
                }
            }
        }
        printf("%d\n", dp[L1][L2]);
    }
    return 0;
}