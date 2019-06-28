#include <bits/stdc++.h>
using namespace std;

int GetMissNum(vector<int> v) {
    int st = 0, ed = v.size()-1;
    int mid = (st+ed)/2;
    while (st <= ed) {
        if (v[mid] != mid && (mid == 0 || v[mid-1] == mid-1)) {
            return mid;
        } else if (v[mid] != mid) {
            ed == mid-1;
        } else if (v[mid] == mid) {
            st = mid+1;
        }
        mid = (st+ed)/2;
    }
}