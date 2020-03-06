#include "stdio.h"

// 欧几里得算法：a和b(a > b)的最大公约数和b, a%b的最大公约数是相同的
// 若a,b中有一数为0，则最大公约数为非零的那个，否则不存在

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF) {
        printf("%d\n", gcd(a, b));
    }
    return 0;
}