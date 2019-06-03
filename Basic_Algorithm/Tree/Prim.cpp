#include <bits/stdc++.h>
using namespace std;

/*
 *  Prim算法的思想与Dijkstra类似，每次找到距离最小的点
 *  去感染周围的点；区别是数组d的意义不同，Dijkstra指该点到起始点的距离，
 *  而Prim指该点到最小生成树集合的距离，所以更新的方式不同
 */

const int MAXN = 100;

// 最大结点数，图的邻接矩阵表示
int n, G[MAXN][MAXN];
// 每个点到集合的最短距离
int d[MAXN];
// 标记某个点是否被访问过
bool visited[MAXN] = {false};

int Prim() {
    fill(d, d+MAXN, INT_MAX);
    // 从0结点开始建立最小生成树的集合
    d[0] = 0;
    int ans = 0;
    for (int i = 0; i < n; i ++ ) {
        int u = -1, MIN = INT_MAX;
        for (int j = 0; j < n; j ++ ) {
            if (!visited[j] && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) return -1;
        visited[u] = true;
        ans += d[u];
        for (int v = 0; v < n; v ++ ) {
            if (!visited[v] && G[u][v] != INT_MAX) {
                // 与Dijkstra的区别
                if (G[u][v] < d[v]) {
                    d[v] = G[u][v];
                }
            }
        }
    }
    return ans;
}