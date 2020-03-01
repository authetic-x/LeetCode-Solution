#include "stdio.h"
#include "algorithm"
using namespace std;

// 如何用固定价值换取最多重量的商品，计算性价比，然后排序
// 这道题注意值的类型，该用浮点的要用浮点

struct goods {
    double j; // 重量
    double f; // 价值
    double s; // 性价比
}buf[1000];

bool cmp(goods a, goods b) {
    return a.s > b.s;
}

int main() {
    double m;
    int n;
    while (scanf("%lf%d", &m, &n) != EOF && m != -1 && n != -1) {
        for (int i = 0; i < n; i ++ ) {
            scanf("%lf%lf", &buf[i].j, &buf[i].f);
            buf[i].s = buf[i].j / buf[i].f;
        }
        sort(buf, buf + n, cmp);
        int idx = 0;
        double ans = 0;
        while (m > 0 && idx < n) {
            if (m >= buf[idx].f) {
                m -= buf[idx].f;
                ans += buf[idx].j;
            } else {
                ans += buf[idx].j * m / buf[idx].f;
                m = 0;
            }
            idx++;
        }
        printf("%.3lf\n", ans);
    }
}