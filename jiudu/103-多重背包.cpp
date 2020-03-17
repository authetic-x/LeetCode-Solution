#include "stdio.h"

/*
    多重背包问题：物品可被多选但数量有所限制
    完全可以将所有物品拆分为单个个体，这样就是01背包的问题，
    优化情况是将物品个数按二进制划分，因为这样可以组成任意
    大小的物品组合，又降低了时间复杂度，二进制的奇妙之处
*/

struct E {
    int w, v;
}list[2001];

int dp[101];

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int s, n;
        scanf("%d%d", &s, &n);
        int cnt = 0;
        for (int i = 0; i < n; i ++ ) {
            int v, w, k;
            scanf("%d%d%d", &w, &v, &k);
            // 拆分该物品集合为二进制小组
            int c = 1;
            while (k - c > 0) {
                k -= c;
                list[++cnt].w = c * w;
                list[cnt].v = c * v;
                c *= 2;
            }
            list[++cnt].w = w * k;
            list[cnt].v = v * k;
        }
        for (int i = 0; i <= s; i ++ ) dp[i] = 0;
        for (int i = 1; i <= cnt; i ++ ) {
            // 这是01背包的情况
            for (int j = s; j >= list[i].w; j -- ) {
                dp[j] = max(dp[j], dp[j-list[i].w] + list[i].v);
            }
        }
        printf("%d\n", dp[s]);
    }
    return 0;
}