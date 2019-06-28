#include <bits/stdc++.h>
using namespace std;

int getFirstK(vector<int> v, int k, int st, int ed) {
    if (st <= ed) {
        int mid = (st + ed) / 2;
        if (v[mid] == k) {
            if (mid == st || v[mid-1] != k) {
                return mid;
            } else {
                ed = mid-1;
            }
        } else if (v[mid] < k) {
            st = mid+1;
        } else {
            ed = mid-1;
        }
        return getFirstK(v, k, st, ed);
    }
    return -1;
}

int getLastK(vector<int> v, int k, int st, int ed) {
    if (st <= ed) {
        int mid = (st + ed) / 2;
        if (v[mid] == k) {
            if (mid == ed || v[mid+1] != k) {
                return mid;
            } else {
                st = mid+1;
            }
        } else if (v[mid] < k) {
            st = mid+1;
        } else {
            ed = mid-1;
        }
        return getLastK(v, k, st, ed);
    }
    return -1;
}

int getNumOfK(vector<int> v, int k) {
    int st = getFirstK(v, k, 0, v.size()-1);
    int ed = getLastK(v, k, 0, v.size()-1);
    return ed-st+1;   
}