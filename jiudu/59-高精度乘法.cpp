#include "stdio.h"
#include "string.h"
#define MAXLEN 210

/*
    两个高精度整数相乘，直接按位计算
    关键是tmp[i+j] += a[i] + b[j] 这一句以及对tmp的调整
*/

struct BigInteger {
    int digit[210];
    int size;

    void init() {
        for (int i = 0; i < 210; i ++ ) digit[i] = 0;
        size = 0;
    }

    void set(char str[]) {
        init();
        int len = strlen(str);
        for (int i = len-1; i >= 0; i -- ) {
            digit[size++] = str[i] - '0';
        }
    }

    void output() {
        for (int i = size-1; i >= 0; i -- ) {
            printf("%d", digit[i]);
        }
        printf("\n");
    }

    BigInteger operator * (const BigInteger &A) const {
        int tmp[410];
        for (int i = 0; i < 410; i ++ ) tmp[i] = 0;
        for (int i = 0; i < size; i ++ ) {
            for (int j = 0; j < A.size; j ++ ) {
                tmp[i+j] += digit[i] * A.digit[j];
            }
        }
        BigInteger ans;
        ans.init();
        int carry = 0;
        for (int i = 0; i < 410; i ++ ) {
            int c = tmp[i] + carry;
            if (c == 0) break;
            ans.digit[ans.size++] = c % 10;
            carry = c / 10;
        }
        return ans;
    }
}a, b;

int main() {
    char str1[200], str2[200];
    while (scanf("%s%s", str1, str2) != EOF) {
        a.set(str1), b.set(str2);
        BigInteger ans = a * b;
        ans.output();
    }
    return 0;
}