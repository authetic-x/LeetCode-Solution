#include "stdio.h"

char maze[101][101];
bool mark[101][101];
int go[][2] = {
    0, 1,
    0, -1,
    1, 0,
    -1, 0,
    1, 1,
    1, -1,
    -1, -1,
    -1, 1
};
// 地图大小为 m * n
int m, n;

void DFS(int x, int y) {
    for (int i = 0; i < 8; i ++ ) {
        int nx =  x + go[i][0];
        int ny = y + go[i][1];

        if (mark[nx][ny] == true || maze[nx][ny] == '*') continue;
        if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
        mark[nx][ny] = true;
        DFS(nx, ny);
    }
}

int main() {
    while (scanf("%d%d", &m, &n) != EOF) {
        if (m == 0 && n == 0) break;
        for (int i = 0; i < m; i ++ ) {
            scanf("%s", maze[i]);
        }
        for (int i = 0; i < 101; i ++ ) {
            for (int j = 0; j < 101; j ++ ) {
                mark[i][j] = false;
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i ++ ) {
            for (int j = 0; j < n; j ++ ) {
                if (mark[i][j] == false && maze[i][j] == '@') {
                    mark[i][j] = true;
                    DFS(i, j);
                    ans ++;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}