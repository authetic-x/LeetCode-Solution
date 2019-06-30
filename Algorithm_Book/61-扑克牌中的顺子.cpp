#include <bits/stdc++.h>
using namespace std;

bool isContinuous(vector<int> num) {
    if (num.size() != 5) return false;
    sort(num.begin(), num.end());
    int numZero = 0;
    int numGap = 0;
    for (int i = 0; i < num.size(); i ++ ) {
        if (num[i] != 0) break;
        numZero++;
    }
    int small = numZero, big = numZero+1;
    while (big < num.size()) {
        if (num[big] == num[small]) return false;
        numGap += (num[big]-num[small]-1);
        small++, big++;
    }
    if (numGap <= numZero) return true;
    return false;
}