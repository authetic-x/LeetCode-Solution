#include "stdio.h"

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int maxLine = n + (n - 1) * 2;
        for (int i = 0; i < n; i ++ ) {
            for (int j = 0; j < maxLine; j ++ ) {
                if (j < maxLine-(n + i*2)) {
                    printf(" ");
                } else {
                    printf("*");
                }
            }
            printf("\n");
        }
    }
    return 0;
}