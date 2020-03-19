#include "stdio.h"

long long list[201];

int main() {
    int n;
    long long a;
    while (scanf("%d%lld", &n, &a) != EOF) {
        for (int i = 0; i < n; i ++ ) {
            scanf("%lld", &list[i]);
            if (a == list[i]) a *= 2;
        }
        printf("%lld\n", a);
    }
    return 0;
}