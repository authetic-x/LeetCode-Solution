#include "stdio.h"
#include "string.h"

struct bigInteger {
    int digit[1000];
    int size = 0;

    void init() {
        for (int i = 0; i < 1000; i ++ ) digit[i] = 0;
        size = 0;
    }

    void set(int x) {
        do {
            digit[size++] = x % 10000;
            x /= 10000;
        } while (x != 0);
    }

    bigInteger operator * (int x) const {
        bigInteger res;
        res.init();
        int carry = 0, tmp = 0;
        for (int i = 0; i < size; i ++ ) {
            tmp = carry * digit[i] + carry;
            res.digit[res.size++] = tmp % 10000;
            carry = tmp / 10000;
        }
        if (carry != 0) {
            res.digit[res.size++] = carry;
        }
        return res;
    }

    bigInteger operator + (const bigInteger &x) const {
        bigInteger res;
        res.init();
        int carry = 0, tmp;
        for (int i = 0;  i < size || i < x.size; i ++ ) {
            tmp = digit[i] + x.digit[i] + carry;
            res.digit[res.size++] = tmp % 10000;
            carry = tmp / 10000;
        }
        if (carry != 0) {
            res.digit[res.size++] = carry;
        }
        return res;
    }

    bigInteger operator / (int x) const {
        bigInteger res;
        res.init();
        int reminder = 0;
        for (int i = size-1; i >= 0; i -- ) {
            // 商
            int t = (reminder * 10000 + digit[i]) / x;
            // 余数
            int r = (reminder * 10000 + digit[i]) % x;
            res.digit[i] = t;
            reminder = r;
        }
        res.size = 0;
        for (int i = 0; i < 10000; i ++ ) {
            if (res.digit[i] != 0) res.size = i;
        }
        res.size++;
        return res;
    }

    int operator % (int x) const {
        int reminder = 0;
        for (int i = size-1; i >= 0; i -- ) {
            // 商
            int t = (reminder * 10000 + digit[i]) / x;
            // 余数
            int r = (reminder * 10000 + digit[i]) % x;
            reminder = r;
        }
        return reminder;
    }
}a, b, c;

char str[10000];
char ans[10000];

int main() {
    int m, n;
    while (scanf("%d%d", &m, &n) != EOF) {
        scanf("%s", str);
        a.set(0);
        b.set(1);
        int len = strlen(str);
        for (int i = 0; i < len; i ++ ) {
            int t = 0;
            if (str[i] >= '0' && str[i] <= '9') {
                t = str[i] - '0';
            } else {
                t = str[i] - 'A' + 10;
            }
            a = a + b * t;
            b = b * m;
        }
        int size = 0;
        do {
            int t = a % n;
            a = a / n;
            if (t >= 0 && t <= 9) {
                ans[size++] = '0' + t;
            } else {
                ans[size++] = 'a' + (t - 10);
            }
        } while (a.digit[0] != 0 || a.size != 1);
        for (int i = size-1; i >= 0; i -- ) {
            printf("%c", ans[i]);
        }
        printf("\n");
    }
    return 0;
}