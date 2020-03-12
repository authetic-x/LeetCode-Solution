#include "stdio.h"
#include "string.h"

struct bigInteger {
    int digit[1000];
    int size;

    void init() {
        for (int i = 0; i < 1000; i ++ ) digit[i] = 0;
        size = 0;
    }

    void set(int x) {
        init();
        do {
            digit[size++] = x % 10000;
            x /= 10000;
        } while (x != 0);
    }

    void output() {
        for (int i = size-1; i >= 0; i -- ) {
            if (i == size-1) printf("%d", digit[i]);
            else printf("%04d", digit[i]);
        }
        printf("\n");
    }

    bigInteger operator * (int x) const {
        int carry = 0, tmp;
        bigInteger ans;
        ans.init();
        for(int i = 0; i < size; i ++ ) {
            tmp = digit[i] * x + carry;
            carry = tmp / 10000;
            tmp %= 10000;
            ans.digit[ans.size++] = tmp;
        }
        if (carry != 0) {
            ans.digit[ans.size++] = carry;
        }
        return ans;
    }
}a;

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        a.init();
        a.set(1);
        for(int i = n; i >= 1; i -- ) {
            a = a * i;
        }
        a.output();
    }
    return 0;
}