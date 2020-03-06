#include "stdio.h"

/*
    求质因数的个数，如 120 = 2*2*2*3*5，有5个质因数
    方法是先把质数统计起来，依次将n整除到1为止，期间
    统计个数
*/

int prime[100000];
int primeSize;
int mark[100001];

void init() {
    for (int i = 2; i <= 100000; i ++ ) {
        mark[i] = false;
    }
    primeSize = 0;
    for (int i = 2; i <= 100000; i ++ ) {
        if (mark[i]) continue;
        prime[primeSize++] = i;
        for (int j = i*i; j <= 100000; j += i) {
            mark[i] = true;
        }
    }
}

int main() {
    init();
    int n;
    // 不同质因数的个数
    int ansSize = 0;
    int ansNum[30] = {0};
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i <= primeSize; i ++ ) {
            if (n % prime[i] == 0) {
                while (n % prime[i] == 0) {
                    ansNum[ansSize]++;
                    n /= prime[i];
                }
                ansSize++;
            }
            if (n == 1) break;
        }
        if (n != 1) {
            ansNum[ansSize++] = 1;
        }
        int ans = 0;
        for (int i = 0; i < ansSize; i ++ ) {
            ans += ansNum[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}