#include <bits/stdc++.h>
using namespace std;

int indexOfNum(int index) {
    int digit = 1;
    while (1) {
        int numOfDigit;
        if (digit == 1) numOfDigit = 10;
        else numOfDigit = digit*9*(int)pow(10, digit-1);
        if (index < numOfDigit) break;
        index -= numOfDigit;
    }
    int ans = 0;
    if (digit == 1) {
        ans = index;
    } else {
        int p = index / digit;
        int q = index % digit;
        int st = (int)pow(10, digit-1) + p;
        if (q == 0) ans = (st-1) % 10;
        else {
            int i = digit - q;
            while (i -- ) {
                st /= 10;
            }
            ans = st % 10;
        }
    }
    return ans;
}