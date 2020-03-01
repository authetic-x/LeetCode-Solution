#include "stdio.h"
#include "algorithm"
using namespace std;

// AC 80%

long long list[100001];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < 3 * n; i ++ ) {
            scanf("%d", &list[i]);
        }
        long long ans = 0;
        sort(list, list + 3 * n);
        for (int i = 3 * n - 1; i >= n; i -= 2) {
            ans += list[i - 1]; 
        }
        printf("%lld\n", ans);
    }
    return 0;
}