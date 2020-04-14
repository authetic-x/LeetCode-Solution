/*
    题目大意是：给出n个格子，只有红黄蓝三种颜色，要求相邻不同颜色，
    首尾不同颜色，问有多少种组合方式
    类似于这种求组合方式的题目一般都是dfs，找准状态，记住递归到i时，
    i的状态是已经设置了的。回溯时要还原状态
*/

#include "stdio.h"

int list[101];
int ans = 0;

int n;

void dfs(int i) {
    if (i == n) {
        if (list[i] != list[1]) ans++;
        return;
    }
    for (int j = 1; j <= 3; j ++ ) {
        if (j != list[i]) {
            list[i+1] = j;
            dfs(i+1);
            list[i+1] = 0;
        }
    }
}

int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; i ++ ) list[i] = 0;
        ans = 0;
        // 1, 2, 3分别代表三种颜色
        for (int i = 1; i <= 3; i ++ ) {
            list[1] = i;
            dfs(1);
        }
        printf("%d\n", ans);
    }
    return 0;
}