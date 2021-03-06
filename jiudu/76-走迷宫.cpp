#include "stdio.h"

char maze[8][8];
int n, m, t;
bool success;
int go[][2] = {
    0, 1,
    0, -1,
    1, 0,
    -1, 0
};

void DFS(int x, int y, int time) {
    for (int i = 0; i < 4; i ++ ) {
        int nx = x + go[i][0];
        int ny = y + go[i][1];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (maze[nx][ny] == 'X') continue;
        if (maze[nx][ny] == 'D') {
            if (time + 1 == t) {
                success = true;
                return;
            }
            continue;
        }
        maze[nx][ny] = 'X';
        DFS(nx, ny, time+1);
        maze[nx][ny] = '.';
    } 
}

int main() {
    while (scanf("%d%d%d", &n, &m, &t) != EOF) {
        if (n == 0 && m == 0 && t == 0) break;
        for (int i = 0; i < n; i ++ ) {
            scanf("%s", maze[i]);
        }
        success = false;
        for (int i = 0; i < n; i ++ ) {
            for (int j = 0; j < m; j ++ ) {
                if (maze[i][j] == 'S') {
                    maze[i][j] = 'X';
                    DFS(i, j, 0);
                    break;
                }
            }
        }
        puts(success ? "YES" : "NO");
    }
    return 0;
}