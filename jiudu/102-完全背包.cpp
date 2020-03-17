#include "stdio.h"

/*
    首先完全背包指物品可被无限选择，若要求背包被恰好装满，
    只需标记某个j状态是否存在
    完全背包之所以用顺序遍历，dp[j]之所以可用dp[j-list[i].w]
    转换过来是因为后者状态可能是还没有选i，也可能是已经选了多个i，
    所以完全背包更适合用一维数组来做。
    总之每轮物品的遍历，原则上都保证了所有的状态j在前i个物品的选择中保持了
    最优解，这也是dp最具有魔力的地方
*/

struct E {
    int w, v;
}list[501];

int dp[10001];

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int T;
    while(T--) {
        int s, tmp;
        scanf("%d%d", &tmp, &s);
        s -= tmp;
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i ++ ) {
            scanf("%d%d", &list[i].w, &list[i].v);
        }
        for (int i = 0; i <= s; i ++ ) dp[i] = -1;
        dp[0] = 0;
        for (int i = 0; i < n; i ++ ) {
            for (int j = list[i].w; j <= s; j ++ ) {
                if (dp[j-list[i].w] != -1) {
                    dp[j] = min(dp[j], dp[j-list[i].w] + list[i].v);
                }
            }
        }

        if (dp[s] != -1) {
            printf("Impossible\n");
        } else {
            printf("%d\n", dp[s]);
        }
    }
    return 0;
}