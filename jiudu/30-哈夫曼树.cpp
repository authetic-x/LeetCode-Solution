#include "stdio.h"
#include "queue"
using namespace std;

/*
    这里求权重总和的方式很巧妙，每次堆中元素个数大于1时，去
    最小堆中取出两个元素，将两个数的和加到结果中，并将和值
    推入堆中，并不需要用权重乘以路径长度的方式去求
*/

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