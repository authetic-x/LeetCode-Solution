#include "stdio.h"

/*
    求a的b次方。这是一种很有意思的解法，将b拆解为二进制，
    如5 => 101，a^5 = a^1 * a^4
    比较难理解的是结果取后三位，计算的过程也要将a的n次方取
    后三位
*/

int main() {
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF) {
        int ans = 1;
        while (b != 0) {
            if (b%2 == 1) {
                ans *= a;
                // 取后三位
                ans %= 1000;
            }
            b /= 2;
            a *= a;
            a %= 1000;
        }
        printf("%d\n", ans);
    }
    return 0;
}