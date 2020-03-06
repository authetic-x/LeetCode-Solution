#include "stdio.h"

int main() {
    // 取模数位拆解的方法
    /* int a, b;
    int ans;
    while (scanf("%d%d", &a, &b) != EOF) {
        if (a == 0 || b == 0) {
            printf("0\n");
            continue;
        }
        int buf1[15], buf2[15], size1 = 0, size2 = 0;
        while (a != 0) {
            buf1[size1++] = a % 10;
            a /= 10;
        }
        while (b != 0) {
            buf2[size2++] = b % 10;
            b /= 10;
        }
        for (int i = 0; i < size1; i ++ ) {
            for (int j = 0; j < size2; j ++ ) {
                ans += buf1[i] * buf2[j];
            }
        }
        printf("%d\n", ans);
    } */
    // 利用字符串的方法
    char str1[15], str2[15];
    while (scanf("%s%s", str1, str2) != EOF) {
        int ans = 0;
        for (int i = 0; str1[i] != 0; i ++ ) {
            for (int j = 0; str2[j] != 0; j ++ ) {
                ans += (str1[i] - '0') * (str2[j] - '0');
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}