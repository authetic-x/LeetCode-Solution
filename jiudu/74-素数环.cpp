#include "stdio.h"

/*
    写回溯问题的关键是找准有哪些状态以及何时设置状态
    我们一般会提前设置好下一个节点的状态，因为这样可以
    方便的在递归函数开头进行判断。还要注意不要忘记还原
    节点的状态标记
*/

int ans[22];
bool hash[22];
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};

int n;

// 判断一个数是否是素数
bool judge(int x) {
    for (int i = 0; i < 13; i ++ ) {
        if (x == prime[i]) return true;
    }
    return false;
}

void check() {
    if (judge(ans[n] + ans[1]) == false) return;
    for (int i = 1; i <= n; i ++ ) {
        if (i != 1) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
}

void DFS(int num) {
    if (num > 1) {
        if (judge(ans[num] + ans[num-1]) == false) return;
    }
    if (num == n) {
        check();
        return;
    }

    for (int i = 2; i <= n; i ++ ) {
        if (hash[i]) continue;
        hash[i] = true;
        ans[num+1] = i;
        DFS(num+1);
        hash[i] = false;
    }
}

int main() {
    int Case = 0;
    while(scanf("%d", &n) != EOF) {
        for (int i = 0; i < 22; i ++ ) hash[i] = false;
        ans[1] = 1;
        hash[1] = true;
        Case ++;
        printf("Case %d:\n", Case);
        DFS(1);
    }
    return 0;
}