#include "stdio.h"

char buf[82][82];

/*
    出现了一个很奇怪的错误，输出的字符一直是同一个，
    目前无法debug出来!
    果然是自己傻逼了，永远不要试图怀疑是计算机的问题，
    这是一个愚蠢到不能再愚蠢的假设。在写这类逻辑有点
    复杂的算法时，自负是很恐怖的，会浪费更多的时间，
    可以说，如何输出结果不对，一定是你写的有问题！
*/

int main() {
    int n;
    char a, b;
    bool firstOutput = true;
    // 记住，连续输入字符时要加空格，不加会将a赋值给空格
    while (scanf("%d %c %c", &n, &a, &b) == 3) {
        if (firstOutput) {
            firstOutput = false;
        } else {
            printf("\n");
        }
        // cnt为步长
        int x = n / 2 + 1, y = x, cnt = 0;
        for (int i = 0; i <= n/2; i ++ ) {
            int xx = x - i, yy = y - i;
            char ch = i % 2 == 0 ? a : b;
            for (int j = 0; j <= cnt; j ++ ) {
                buf[xx][yy + j] = ch;
                buf[xx + j][yy] = ch;
                buf[xx + cnt][yy + j] = ch;
                buf[xx + j][yy + cnt] = ch;
            }
            cnt += 2;
        }
        if (n != 1) {
            buf[1][1] = ' ';
            buf[1][n] = ' ';
            buf[n][1] = ' ';
            buf[n][n] = ' ';
        }
        for (int i = 1; i <= n; i ++ ) {
            for (int j = 1; j <= n; j ++ ) {
                printf("%c", buf[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}