#include <bits/stdc++.h>
using namespace std;

/*
 *  首先我真的服了，在输入输出这里搞了一个晚上，至今不知道原因
 *  其次，好像用不着什么优先队列，普通队列答案也是正确的，加强版的dfs，
 *  有难度，主要是题目新颖
 */

const int N = 55;
bool vis[N][N][N][N];
char maze[N][N];
int m,n,px,py,boxx,boxy,ex,ey;
int dir[][2] = {0,1,0,-1,1,0,-1,0}; 
int step = 1e9;

struct Node {
    int px, py, boxx, boxy, step;
}s;

bool judge(int x, int y) {
    if (x < 0 || x >= m || y < 0 || y >= n || maze[x][y] == '#') {
        return false;
    }
    return true;
}

int bfs() {
    s = {px, py, boxx, boxy, 0};
    queue<Node> q;
    q.push(s);
    vis[px][py][boxx][boxy] = 1;
    while (!q.empty()) {
        Node u = q.front(); q.pop();
        if (u.boxx == ex && u.boxy == ey) {
            return u.step;
        }
        for (int i = 0; i < 4; i ++ ) {
            int px = u.px + dir[i][0];
            int py = u.py + dir[i][1];
            int boxx = u.boxx, boxy = u.boxy;
            if (px == u.boxx && py == u.boxy) {
                boxx += dir[i][0];
                boxy += dir[i][1];
            }
            if (!judge(px, py) || !judge(boxx, boxy)) continue;
            if (vis[px][py][boxx][boxy]) continue;
            vis[px][py][boxx][boxy] = 1;
            q.push({px, py, boxx, boxy, u.step+1});
        }
    }
    return -1;
}

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i ++ ) {
        scanf("%s", maze[i]);
        printf("%s\n", maze[i]);
        for (int j = 0; j < n; j ++ ) {
            if (maze[i][j] = '0') px = i, py = j, maze[i][j] = '.';
            if (maze[i][j] == 'S') boxx = i, boxy = j, maze[i][j] = '.';
            if (maze[i][j] == 'E') ex = i, ey = j, maze[i][j] = '.';
        }
    }
    printf("%d\n", bfs());
    return 0;
}