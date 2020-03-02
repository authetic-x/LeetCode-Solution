#include "stdio.h"
#include "queue"
using namespace std;

// 版本太低可能用不了
priority_queue<int, vector<int>, greater<int>> q;

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        while (!q.empty()) q.pop();
        for (int i = 0; i < n; i ++ ) {
            int x;
            scanf("%d", &x);
            q.push(x);
        }
        int ans = 0;
        while (q.size() > 1) {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            ans += a + b;
            q.push(a + b);
        }
        printf("%d\n", ans);
    }
    return 0;
}