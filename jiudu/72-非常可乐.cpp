#include "stdio.h"
#include "queue"
using namespace std;

int mark[101][101][101];

struct N {
    int a, b, c;
    int t;

    void init(int ta, int tb, int tc) {
        a = ta;
        b = tb;
        c = tc;
    }
};

queue<N> q;

// sa,sb为杯子的容量
void AtoB(int &a, int sa, int &b, int sb) {
    if (sb - b >= a) {
        a = 0;
        b += a;
    } else {
        a -= sb - b;
        b = sb;
    }
}

bool isEven(int a, int b, int c, int s) {
    if (a == s / 2 && b == s / 2) return true;
    if (a == s / 2 && c == s / 2) return true;
    if (b == s / 2 && c == s / 2) return true;
    return false;
}

int BFS(int s, int n, int m) {
    while(!q.empty()) {
        N now = q.front();
        q.pop();
        int a, b, c;
        // 六种倾倒状态
        a = now.a, b = now.b, c = now.c;
        AtoB(a, s, b, n);
        if (mark[a][b][c] == false) {
            mark[a][b][c] = true;
            N tmp;
            tmp.init(a, b, c);
            tmp.t = now.t + 1;
            if (isEven(a, b, c, s)) return tmp.t;
            q.push(tmp);
        }
        a = now.a, b = now.b, c = now.c;
        AtoB(a, s, c, m);
        if (mark[a][b][c] == false) {
            mark[a][b][c] = true;
            N tmp;
            tmp.init(a, b, c);
            tmp.t = now.t + 1;
            if (isEven(a, b, c, s)) return tmp.t;
            q.push(tmp);
        }
        a = now.a, b = now.b, c = now.c;
        AtoB(b, n, c, m);
        if (mark[a][b][c] == false) {
            mark[a][b][c] = true;
            N tmp;
            tmp.init(a, b, c);
            tmp.t = now.t + 1;
            if (isEven(a, b, c, s)) return tmp.t;
            q.push(tmp);
        }
        a = now.a, b = now.b, c = now.c;
        AtoB(b, n, a, s);
        if (mark[a][b][c] == false) {
            mark[a][b][c] = true;
            N tmp;
            tmp.init(a, b, c);
            tmp.t = now.t + 1;
            if (isEven(a, b, c, s)) return tmp.t;
            q.push(tmp);
        }
        a = now.a, b = now.b, c = now.c;
        AtoB(c, m, a, s);
        if (mark[a][b][c] == false) {
            mark[a][b][c] = true;
            N tmp;
            tmp.init(a, b, c);
            tmp.t = now.t + 1;
            if (isEven(a, b, c, s)) return tmp.t;
            q.push(tmp);
        }
        a = now.a, b = now.b, c = now.c;
        AtoB(c, m, b, n);
        if (mark[a][b][c] == false) {
            mark[a][b][c] = true;
            N tmp;
            tmp.init(a, b, c);
            tmp.t = now.t + 1;
            if (isEven(a, b, c, s)) return tmp.t;
            q.push(tmp);
        }
    }
    return -1;
}

int main() {
    int s, n, m;
    while (scanf("%d%d%d", &s, &n, &m) != EOF) {
        if (s == 0 && n == 0 && m == 0) break;
        if (s % 2 == 1) {
            printf("NO\n");
            continue;
        }
        N tmp;
        tmp.init(s, 0, 0);
        tmp.t = 0;
        while (!q.empty()) q.pop();
        q.push(tmp);
        for (int i = 0; i < 101; i ++ ) {
            for (int j = 0; j < 101; j ++ ) {
                for (int k = 0; k < 101; k ++ ) {
                    mark[i][j][k] = false;
                }
            }
        }
        mark[s][0][0] = true;
        int ans = BFS(s, n, m);
        if (ans != -1) {
            printf("%d\n", ans);
        } else {
            printf("NO\n");
        }
    }
    return 0;
}