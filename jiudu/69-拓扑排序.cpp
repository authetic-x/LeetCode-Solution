#include "stdio.h"
#include "queue"
#include "vector"
using namespace std;

vector<int> G[101];
queue<int> q;
int inDegree[101];

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        if (n == 0 && m == 0) break;
        for (int i = 0; i <= n; i ++ ) {
            inDegree[i] = 0;
            G[i].clear();
        }
        int u, v;
        for (int i = 0; i < m; i ++ ) {
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            inDegree[v]++;
        }
        for (int i = 1; i <= n; i ++ ) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        int cnt = 0;
        while (!q.empty()) {
            u = q.front();
            q.pop();
            cnt++;
            for (int i = 0; i < G[u].size(); i ++ ) {
                v = G[u][i];
                inDegree[v]--;
                if (inDegree[v] == 0) q.push(v);
            }
            G[u].clear();
        }
        if (cnt == n) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}