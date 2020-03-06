#include "stdio.h"

// 最小公倍数=a*b/最大公约数

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF) {
        printf("%d\n", a * b / gcd(a, b));
    }
    return 0;
}