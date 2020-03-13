#include "stdio.h"
#include "queue"
using namespace std;

/*
    关键是意识到每个点的状态只有一种，因为最先更新的点t一定最小
*/

int maze[50][50][50];
int mark[50][50][50];

struct N {
    int x, y, z;
    int t;
};

int go[][3] = {
    1, 0, 0,
    -1, 0, 0,
    0, 1, 0,
    0, -1, 0,
    0, 0, 1,
    0, 0, -1
};

queue<N> q;

int BFS(int a, int b, int c) {
    while (!q.empty()) {
        N now = q.front();
        q.pop();
        for (int i = 0; i < 6; i ++ ) {
            int nx = now.x + go[i][0];
            int ny = now.y + go[i][1];
            int nz = now.z + go[i][2];
            if (nx < 0 || nx >= a || ny < 0 || ny >= b || nz < 0 || nz >= c) {
                continue;
            }
            if (maze[nx][ny][nz] == 1 || mark[nx][ny][nz]) continue;
            N tmp;
            tmp.x = nx;
            tmp.y = ny;
            tmp.z = nz;
            tmp.t = now.t + 1;
            q.push(tmp);
            mark[nx][ny][nz] = true;
            if (nx == a-1 && ny == b-1 && nz == c-1) return tmp.t;
        }
    }
    return -1;
}

int main() {
    int T;
    scanf("%d", &T);
    int a, b, c, t;
    while (T--) {
        scanf("%d%d%d%d", &a, &b, &c, &t);
        for (int i = 0; i < a; i ++ ) {
            for (int j = 0; j < b; j ++ ) {
                for (int k = 0; k < c; k ++ ) {
                    scanf("%d", &maze[i][j][k]);
                }
            }
        }
        for (int i = 0; i < 50; i ++ ) {
            for (int j = 0; j < 50; j ++ ) {
                for (int k = 0; k <= 50; k ++ ) {
                    mark[i][j][k] = false;
                }
            }
        }
        // 清空队列
        while (!q.empty()) q.pop();
        mark[0][0][0] = true;
        N tmp;
        tmp.x = tmp.y = tmp.z = tmp.t = 0;
        q.push(tmp);
        int ans = BFS(a, b, c);
        if (ans > t || ans == -1) scanf("-1\n");
        else printf("%d\n", ans);
    }
    return 0;
}