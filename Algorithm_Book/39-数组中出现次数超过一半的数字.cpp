#include <bits/stdc++.h>
using namespace std;

int partion(vector<int> v, int st, int ed) {
    if (st == ed) return st;
    int tmp = v[st];
    int i = st, j = ed;
    while (i < j) {
        while (v[j] > tmp) j--;
        if (i < j) v[i] = v[j];
        while (v[i] <= tmp) i++;
        if (i < j) v[j] = v[i];
    }
    v[i] = tmp;
    return i;
}

int MorethanHalf01(vector<int> v) {
    if (v.size() == 0) return -1;
    int len = v.size();
    int middle = len >> 1;
    int st = 0, ed = len-1;
    int idx = partion(v, st, ed);
    while (idx != middle) {
        if (idx > middle) {
            idx = partion(v, st, idx-1);
        } else {
            idx = partion(v, idx+1, ed);
        }
    }
    return v[idx];
}

int MorethanHalf02(vector<int> v) {
    if (v.size() == 0) return -1;
    int ans = v[0], cnt = 1;
    for (int i = 1; i < v.size(); i ++ ) {
        if (ans = v[i]) cnt++;
        else {
            if (cnt <= 0) {
                ans = v[i];
                cnt ++;
            } else cnt--;
        }
    }
    return ans;
}