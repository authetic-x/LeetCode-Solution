#include <bits/stdc++.h>
using namespace std;

/*
 *  dp解法也不是很难，难在如何用二维数组表示要去哪些城市，
 *  聪明的网友的做法是用二进制，去为1不去为0，再转换为10进制
 *  测试还是通不过！！！
 */

int main() {
    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n));
    for (int i = 0; i < n; i ++ ) {
        for (int j = 0; j < n; j ++ ) {
            cin >> m[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(1 << (n-1)+1));
    for (int j = 1; j < 1 << (n-1); j ++ ) {
        for (int i = 0; i < n; i ++ ) {
            dp[i][j] = INT_MAX;
            if ((j >> (i-1)) & 1 == 1) continue;

            for (int k = 1; k < n; k ++ ) {
                if ((j >> (k-1)) & 1 == 0) continue;
                if (dp[i][j] > m[i][k] + dp[i][j ^ (1 << (k-1))]) {
                    dp[i][j] = m[i][k] + dp[i][j ^ (1 << (k-1))];
                }
            }
        }
    }
    cout << dp[0][(1 << (n-1))-1] << endl;
    return 0;
}

/*
Info: 暴力解法运行case通过为0，不知道哪里错了

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
*/