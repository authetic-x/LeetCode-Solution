#include "stdio.h"
#include "algorithm"
using namespace std;
#define INF 1000000000

/*
    算是比较难的一类dp，关键是得出相邻疲劳度最小的结论
*/

int list[2001];
int dp[1001][2001];

int main() {
    int n, k;
    while (scanf("%d%d", &n, &k) != EOF) {
        for (int i = 1; i <= n; i ++ ) {
            scanf("%d", &list[i]);
        }
        sort(list, list + n);
        for (int i = 1; i <= k; i ++ ) {
            for (int j = 2 * i; j <= n; j++) {
                if (j > 2 * i) {
                    dp[i][j] = dp[i][j - 1];
                } else {
                    dp[i][j] = INF;
                }
                int tmp = (list[j] - list[j - 1]) * (list[j] - list[j - 1]);
                if (dp[i][j] > dp[i - 1][j - 2] + tmp) {
                    dp[i][j] = dp[i - 1][j - 2] + tmp;
                }
            }
        }
        printf("%d\n", dp[k][n]);
    }
}