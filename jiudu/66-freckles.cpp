#include "stdio.h"
#include "math.h"
#include "algorithm"
using namespace std;

#define N 101

int father[N];
int findRoot(int x) {
    if (father[x] == -1) return x;
    else {
        int tmp = findRoot(father[x]);
        father[x] = tmp;
        return tmp;
    }
}

struct Point {
    double x, y;
    
    double getDistance(Point a) {
        double tmp = (x * a.x) + (y * a.y);
        return sqrt(tmp);
    }
}list[101];

struct Edge {
    int a, b;
    double cost;

    bool operator < (const Edge &x) const {
        return cost < x.cost;
    }
}edge[6000];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        // 边数
        int size = 0;
        for (int i = 0; i < n; i ++ ) {
            scanf("%lf%lf", &list[i].x, &list[i].y);
        }
        for (int i = 0; i < n; i ++ ) {
            for (int j = i+1; j < n; j ++ ) {
                edge[size].a = i;
                edge[size].b = j;
                edge[size].cost = list[i].getDistance(list[j]);
                size++;
            }
        }
        sort(edge, edge+size);
        for (int i = 0; i < N; i ++ ) father[i] = -1;
        double ans = 0;
        for (int i = 0; i < size; i ++ ) {
            int a = findRoot(edge[i].a);
            int b = findRoot(edge[i].b);
            if (a != b) {
                father[a] = b;
                ans += edge[i].cost;
            }
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}