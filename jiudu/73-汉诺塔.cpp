#include "stdio.h"

// 必须先将所有的盘子移到第二根柱子，再移到第三根柱子

int F(int n) {
    if (n == 1) return 2;
    return 3 * F(n-1) + 2;
}