#include "stdio.h"
#define N 1010
#define INF 1000000000

int G[N][N], weight[N][N], d[N], w[N];
bool visited[N];

void init() {
    for (int i = 0; i < N; i ++ ) {
        d[i] = INF;
        w[i] = INF;
        visited[i] = false;
    }
    for (int i = 0; i < N; i ++ ) {
        for (int j = 0; j < N; j ++ ) {
            G[i][j] = INF;
        }
    }
}

void dijkstra(int n, int s) {
    d[s] = 0;
    w[s] = 0;
    for (int i = 0; i < n; i ++ ) {
        int u = -1;
        int MIN = INF;
        for (int j = 1; j <= n; j ++ ) {
            if (d[j] < MIN && !visited[j]) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) return;
        visited[u] = true;
        for (int v = 1; v <= n; v ++ ) {
            if (G[u][v] != INF && !visited[v]) {
                if (G[u][v] + d[u] < d[v]) {
                    d[v] = G[u][v] + d[u];
                    w[v] = weight[u][v] + w[u];
                } else if (G[u][v] + d[u] == d[v] && weight[u][v] + w[u] < w[v]) {
                    w[v] = weight[u][v] + w[u];
                }
            }
        }
    }
}

int main() {
    int n, m, s, t;
    while (scanf("%d%d", &n, &m) != EOF) {
        if (n == 0 && m == 0) break;
        init();
        int u, v, cost, wgt;
        for (int i = 0; i < m; i ++ ) {
            scanf("%d%d%d%d", &u, &v, &cost, &wgt);
            G[u][v] = cost;
            G[v][u] = cost;
            weight[u][v] = wgt;
            weight[v][u] = wgt;
        }
        scanf("%d%d", &s, &t);
        dijkstra(n, s);
        printf("%d %d\n", d[t], w[t]);
    }
    return 0;
}