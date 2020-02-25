#include "stdio.h"

int main() {
    int n;
    while (scanf("%d", &n) != EOF && n != 0) {
        int hash[101] = {0};
        int grade;
        for (int i = 0; i < n; i ++ ) {
            scanf("%d", &grade);
            hash[grade]++;
        }
        scanf("%d", &grade);
        printf("%d\n", hash[grade]);
    }
    return 0;
}