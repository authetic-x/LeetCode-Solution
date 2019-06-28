#include <bits/stdc++.h>
using namespace std;

int GetNumSameAsIndex(vector<int> v) {
    int st = 0, ed = v.size()-1;
    while (st <= ed) {
        int mid = (st+ed) / 2;
        if (v[mid] == mid) return mid;
        if (v[mid] < mid) st = mid+1;
        else ed = mid-1;
    }
    return -1;
}