#include <bits/stdc++.h>
using namespace std;

vector<int> multiply(vector<int> a) {
    vector<int> left(a.size()), ans(a.size()), right(a.size());
    left[0] = 1;
    for (int i = 1; i < a.size(); i ++ ) {
        left[i] = left[i-1]*a[i-1];
    }
    right[a.size()-1] = 1;
    for (int i = a.size()-2; i >= 0; i -- ) {
        right[i] = right[i+1]*a[i+1];
    }
    for (int i = 0; i < a.size(); i ++ ) {
        ans[i] = left[i] * right[i];
    }
    return ans;
}