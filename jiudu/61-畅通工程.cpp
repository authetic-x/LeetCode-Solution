#include "stdio.h"

int father[1000];

int findRoot(int x) {
    if (father[x] == -1) return x;
    else {
        int tmp = findRoot(father[x]);
        // 路径压缩
        father[x] = tmp;
        return tmp;
    }
}

int main() {
    int n, m;
    while (scanf("%d", &n) != EOF && n != 0) {
        for (int i = 0; i <= n; i ++ ) father[i] = -1;
        scanf("%d", &m);
        int a, b;
        for (int i = 0; i < m; i ++ ) {
            scanf("%d%d", &a, &b);
            a = findRoot(a);
            b = findRoot(b);
            if (a != b) father[a] = b;
        }
        int ans = 0;
        for (int i = 1; i <= n; i ++ ) {
            if (father[i] == -1) ans++;
        }
        printf("%d\n", ans-1);
    }
    return 0;
}