#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;

// 最大结点数，图的邻接矩阵表示
int n, G[MAXN][MAXN];
// 起始点到每个点的最短距离
int d[MAXN];
// 标记某个点是否被访问过
bool visited[MAXN] = {false};

void Dijkstra(int s) {
    fill(d, d+MAXN, INT_MAX);
    d[s] = 0;
    for (int i = 0; i < n; i ++ ) {
        int u = -1, MIN = INT_MAX;
        // 每次都找到一个距离起始点最短且未被访问的点
        for (int j = 0; j < n; j ++ ) {
            if (!visited[j] && d[j] < MIN) {
                MIN = d[j];
                u = j;
            }
        }
        if (u == -1) return;
        visited[j] = true;
        // 从这个点去更新周围还未被访问的点
        for (int v = 0; v < n; v ++ ) {
            if (!visited[v] && G[u][v] != INT_MAX) {
                if (d[u]+G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                }
            }
        }
    }
}