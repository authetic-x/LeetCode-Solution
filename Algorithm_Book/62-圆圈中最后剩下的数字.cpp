#include <bits/stdc++.h>
using namespace std;

int lastNum(int n, int m) {
    if (n == 1) return 0;
    int last = 0;
    for (int i = 2; i <= n; i ++ ) {
        last = (last+m)%i;
    }
    return last;
}