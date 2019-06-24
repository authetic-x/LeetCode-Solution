#include <bits/stdc++.h>
using namespace std;

int InversPairs(vector<int> v) {
    if (v.size() == 0) return 0;
    sort(v.begin(), v.end());
    int cnt = 1;
    for (int i = 1; i < v.size(); i ++ ) {
        if (v[i] == v[i-1]) continue;
        cnt ++;
    }
    return (cnt-1) * cnt / 2;
}