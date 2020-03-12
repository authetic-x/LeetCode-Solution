#include "stdio.h"
#define N 1000001

int father[N];
// 记录集合的节点个数
int sum[N];

int findRoot(int x) {
    if (father[x] == -1) return x;
    else {
        int tmp = findRoot(father[x]);
        father[x] = tmp;
        return tmp;
    }
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= N; i ++ ) {
            father[i] = -1;
            sum[i] = 1;
        }
        int a, b;
        for (int i = 0; i < n; i ++ ) {
            scanf("%d%d", &a, &b);
            a = findRoot(a);
            b = findRoot(b);
            if (a != b) {
                father[a] = b;
                sum[b] += sum[a];
            }
        }
        int ans = 1;
        for (int i = 1; i <= N; i ++ ) {
            if (father[i] == -1 && sum[i] > ans) {
                ans = sum[i];
            }
        }
        printf("%d\n");
    }
    return 0;
}