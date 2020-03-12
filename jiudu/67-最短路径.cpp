#include "stdio.h"
#define N 101
#define INF 1000000000

int G[N][N], d[N];
bool visited[N];

void init() {
    for (int i = 0; i < N; i ++ ) {
        d[i] = INF;
        visited[i] = false;
    }
    for (int i = 0; i < N; i ++ ) {
        for (int j = 0; j < N; j ++ ) {
            G[i][j] = INF;
        }
    }
}

// n为点的个数
void dijkstra(int n) {
    d[1] = 0;
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
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                }
            }
        }
    }
}

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        if (n == 0 && m == 0) break;
        init();
        int u, v, c;
        for (int i = 0; i < m; i ++ ) {
            scanf("%d%d%d", &u, &v, &c);
            G[u][v] = c;
            G[v][u] = c;
        }
        dijkstra(n);
        printf("%d\n", d[n]);
    }
    return 0;
}