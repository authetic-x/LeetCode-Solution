#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 跳台阶问题
 *  Key: 斐波那契数列换了种说法而已，最初写的是递归，
 *       但运行超时，迭代就好了！
 */

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int a[n+1];
        a[0] = 0, a[1] = 1, a[2] = 2;
        if (n <= 2) return a[n];
        for (int i = 3; i <= n; i ++ ) {
            a[i] = a[i-1]+a[i-2];
        }
        return a[n];
    }
};