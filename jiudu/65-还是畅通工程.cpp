#include "stdio.h"
#include "algorithm"
using namespace std;

#define N 101

int father[N];

int findRoot(int x) {
    if (father[x] == -1) return x;
    else {
        int tmp = findRoot(father[x]);
        // 路径压缩
        father[x] = tmp;
        return tmp;
    }
}

struct Edge {
    int a, b;
    int cost;

    bool operator < (const Edge &x) const {
        return cost < x.cost;
    }
} edge[6000];

int main() {
    int n;
    int a, b, cost;
    while (scanf("%d", &n) != EOF && n != 0) {
        for (int i = 0; i < N; i ++ ) father[i] = -1;
        // 边数
        int num = n * (n-1) / 2;
        for (int i = 0; i < num; i ++ ) {
            scanf("%d%d%d", &edge[i].a, &edge[i].b, &edge[i].cost);
        }
        sort(edge, edge+num);
        int ans = 0;
        for (int i = 0; i < num; i ++ ) {
            int root_a = findRoot(edge[i].a);
            int root_b = findRoot(edge[i].b);
            if (root_a != root_b) {
                ans += edge[i].cost;
                father[root_a] = root_b;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}