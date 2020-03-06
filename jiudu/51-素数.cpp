#include "stdio.h"

int prime[10000];
int primeSize;
// 标记某个数为非素数
bool mark[10001];

void init() {
    for (int i = 1; i <= 10000; i ++ ) {
        mark[i] = false;
    }
    primeSize = 0;
    for (int i = 2; i <= 10000; i ++ ) {
        if (mark[i]) continue;
        prime[primeSize++] = i;
        for (int j = i*i; j <= 10000; j += i) {
            mark[j] = true;
        }
    }
}

int main() {
    init();
    int n;
    while (scanf("%d", &n) != EOF) {
        bool output = false;
        for (int i = 0; i < primeSize && prime[i] < n; i ++ ) {
            if (prime[i] % 10 == 1) {
                if (!output) {
                    output = true;
                    printf("%d", prime[i]);
                } else {
                    printf(" %d", prime[i]);
                }
            }
        }
        if (!output) {
            printf("-1\n");
        } else {
            printf("\n");
        }
    }
    return 0;
}