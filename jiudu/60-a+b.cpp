#include "stdio.h"
#include "string.h"

struct bigInteger {
    // 每个数组单元存储一个四位数
    int digit[1000];
    // 数组长度
    int size;
    
    void init() {
        for (int i = 0; i < 1000; i ++ ) digit[i] = 0;
        size = 0;
    }

    void set(char str[]) {
        init();
        int len = strlen(str);
        for (int i = len-1, j = 0, t = 0, c = 1; i >= 0; i -- ) {
            t += (str[i] - '0') * c;
            c *= 10;
            j ++;
            if (j == 4 || i == 0) {
                digit[size++] = t;
                j = 0;
                t = 0;
                c = 1;
            }
        }
    }

    void output() {
        for (int i = size - 1; i >= 0; i -- ) {
            if (i != size-1) printf("%04d", digit[i]);
            else printf("%d", digit[i]);
        }
    }

    bigInteger operator + (const bigInteger &A) const {
        int carry = 0;
        bigInteger res;
        res.init();
        for (int i = 0; i < size || i < A.size; i ++ ) {
            int tmp = digit[i] + A.digit[i] + carry;
            carry = tmp / 10000;
            tmp %= 10000;
            res.digit[res.size++] = tmp;
        }
        // 这一步很容易漏掉
        if (carry != 0) {
            res.digit[res.size++] = carry;
        }
        return res;
    }
}a, b, c;

int main() {
    char str1[1002], str2[1002];
    while (scanf("%s%s", str1, str2) != EOF) {
        a.set(str1);
        b.set(str2);
        c = a + b;
        c.output();
        printf("\n");
    }
}