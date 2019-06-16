#include <iostream>
using namespace std;

/*
 *  Info: 运行case通过为0，不知道哪里错了
 */

int m[25][25];
int n;
int ans = 10000000;
bool visit[25] = {false};

void dfs(int cnt, int cur, int cost) {
    if (cnt == n) {
        cost += m[cur][0];
        if (cost < ans) ans = cost;
        return;
    }
    visit[cur] = true;
    for (int i = 1; i < n; i ++ ) {
        if (!visit[i]) {
            dfs(cnt+1, i, cost+m[cur][i]);
        }
    }
    visit[cur] = false;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++ ) {
        for (int j = 0; j < n; j ++ ) {
            cin >> m[i][j];
        }
    }
    for (int i = 1; i < n; i ++ ) {
        dfs(2, i, m[0][i]);
    }
    cout << ans << endl;
    return 0;
}