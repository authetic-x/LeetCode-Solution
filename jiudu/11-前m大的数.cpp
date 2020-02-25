#include "stdio.h"

int OFFSET = 500000;
int hash[1000001];

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        int x;
        for (int i = 0; i < n; i ++ ) {
            scanf("%d", &x);
            hash[x + OFFSET] = 1;
        }
        for (int i = 500000; i >= -500000; i -- ) {
            if (hash[i + OFFSET] == 1) {
                hash[i + OFFSET] = 0;
                printf("%d", i);
                m--;
                if (m > 0) {
                    printf(" ");
                } else {
                    printf("\n");
                    break;
                }
            }
        }
    }
    return 0;
}