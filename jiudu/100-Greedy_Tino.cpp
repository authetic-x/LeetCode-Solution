#include "stdio.h"
#define INF 100000000
#define OFFSET 2000

/*
    99和100都是比较难的dp，这里的dp表示前i个橘子里重量差为j时的最大结果
*/

int dp[101][4001];
int list[101];

int main() {
    int T, n, cas = 0;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int cnt = 0;
        bool haveZero = false;
        for (int i = 0; i < n; i ++ ) {
            scanf("%d", &list[++cnt]);
            if (list[cnt] == 0) {
                cnt--;
                haveZero = true;
            }
        }
        n = cnt;
        for (int i = -2000; i <= 4000; i ++ ) {
            dp[0][i + OFFSET] = -INF;
        }
        dp[0][0+OFFSET] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = -2000; j <= 2000; j++) {
                int tmp1 = -INF, tmp2 = -INF;
                // 放在第二堆
                if (j + list[i] <= 2000 && dp[i-1][j+OFFSET+list[i]] != -INF) {
                    tmp1 = dp[i-1][j+OFFSET+list[i]] + list[i];
                }
                // 放在第一堆
                if (j-list[i] >= -2000 && dp[i-1][j-list[i]+OFFSET] != -INF) {
                    tmp2 = dp[i-1][j+OFFSET-list[i]] + list[i];
                }
                if (tmp1 < tmp2) {
                    tmp1 = tmp2;
                }
                if (tmp1 < dp[i-1][j+OFFSET]) {
                    tmp1 = dp[i-1][j+OFFSET];
                }
                dp[i][j+OFFSET] = tmp1;
            }
        }
        printf("Case %d: ", ++cas);
        if (dp[n][0+OFFSET] == 0) {
            puts(haveZero == true ? "0" : "-1");
        } else {
            printf("%d\n", dp[n][0 + OFFSET] / 2);
        }
    }
    return 0;
}