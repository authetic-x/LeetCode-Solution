#include <bits/stdc++.h>
using namespace std;

int Pow(int base, int exponent) {
    if (base == 0) return 0;
    if (exponent == 0) return 1;
    if (exponent % 2 == 0) {
        int tmp = Pow(base, exponent >> 1);
        return tmp * tmp;
    } else {
        int tmp = Pow(base, exponent-1);
        return base * tmp;
    }
}