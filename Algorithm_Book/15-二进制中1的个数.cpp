#include <bits/stdc++.h>
using namespace std;

// solution 1
int numOfOne1(int n) {
    if (n == 0) return 0;
    int flag = 1;
    int count = 0;
    while (flag) {
        if (n & flag) {
            count ++;
        }
        flag << 1;
    }
    return count;
}

// 去掉一个数二进制表示最右边的1：将该数与其减1的值做&运算

// solution 2
int numOfOne2(int n) {
    int count = 0;
    while (n) {
        n = (n-1) & n;
        count ++;
    }
    return count;
}