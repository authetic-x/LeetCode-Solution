#include "stdio.h"

/*
    dp表示前i个物品在容量为j时的最优解
    每个物品选或不选，在更新i物品时，保证i-1所有的j状态都已就绪
    用一维数组需要倒序是因为的dp[j]在更新时要保证dp[j-list[i].w]没有
    被覆盖
*/

struct E {
    int w;
    int v;
}list[101];

int max(int a, int b) {
    return a > b ? a : b;
}

int dp[101][101];

int main() {
    int s, n;
    while (scanf("%d%d", &s, &n) != EOF) {
        for (int i = 1; i <= n; i ++ ) {
            scanf("%d%d", &list[i].w, &list[i].v);
        }
        for (int i = 0; i <= s; i ++ ) dp[0][i] = 0;

        for (int i = 1; i <= n; i ++ ) {
            for (int j = s; j >= list[i].w; j -- ) {
                // 选或不选
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-list[i].w] + list[i].v);
            }
            for (int j = list[i].w-1; j >= 0; j -- ) {
                dp[i][j] = dp[i-1][j];
            }
        }
        printf("%d\n", dp[n][s]);
    }
    return 0;
}