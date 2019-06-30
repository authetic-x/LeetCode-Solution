#include <bits/stdc++.h>
using namespace std;

/*
 *  很巧妙的方法，自己想很难想出来
 *  类似题目：不用新的变量交换两个数
 *  1. 基于加减法：
 *     a = a+b
 *     b = a-b
 *     a = a-b
 *  2. 基于异或：
 *     a = a^b
 *     b = a^b
 *     a = a^b
 */

int Add(int num1, int num2) {
    int sum, carry;
    do {
        sum = num1 ^ num2;
        carry = (num1 & num2) << 1;

        num1 = sum;
        num2 = carry;
    } while (num2 != 0);
    return sum;
}