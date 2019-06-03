#include <bits/stdc++.h>
using namespace std;

/*
 *  Kruskal算法采用的是边贪心的思想，将所有的边排序，然后枚举
 *  如果该边的两个顶点已属于同一个集合，就不计入该条边
 */

struct Edge {
    int u, v;
    int val;
}

bool cmp(Edge E1, Edge E2) {
    return E1.val < E2.val
}

const int MAXN = 100;

int father[MAXN];
Edge E[MAXN];

int findFather(int x) {
    while (father[x] != x) {
        x = father[x];
    }
    return x;
}

// n为结点的个数，m为结点的个数
int Kruskal(int n, int m) {
    int ans = 0, numEdge = 0;
    for (int i = 0; i < n; i ++ ) {
        father[i] = i;
    }
    sort(E, E+m, cmp);
    // 枚举所有排序好了的边
    for (int i = 0; i < m; i ++ ) {
        int fatherU = findFather(E[i].u);
        int fatherV = findFather(E[i].v);
        // 判断该边的两个顶点是否属于同一个集合
        if (fatherU != fatherV) {
            // 合并集合
            father[fatherU] = fatherV;
            ans += E[i].val;
            numEdge++;
            if (numEdge == n-1) break;
        }
    }
    if (numEdge != n-1) return -1;
    return ans;
}