#include "stdio.h"

int main() {
    long long a, b;
    int m;
    while (scanf("%d", &m) != EOF && m != 0) {
        scanf("%lld%lld", &a, &b);
        a = a + b;
        int ans[50], size = 0;
        do {
            ans[size++] = a % m;
            a = a / m;
        } while (a != 0);
        for (int i = size-1; i >= 0; i -- ) {
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}