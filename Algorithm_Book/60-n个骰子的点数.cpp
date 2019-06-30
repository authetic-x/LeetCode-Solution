#include <bits/stdc++.h>
using namespace std;

// 递归效率过低，循环性能更好
vector<int> probability(int n) {
    vector<int> tmp(6*n-n+1, 0);
    recursive(tmp, 1, n, 0);
    map<int, double> pro;
    for (int i = 0; i < tmp.size(); i ++ ) {
        if (tmp[i] != 0) {
            pro[i+n] = double(tmp[i]) / double(pow(6, n));
        }
    }

}

// cnt 为点数
void recursive(vector<int> ans, int i, int n, int cnt) {
    if (i == n) {
        for (int j = 1; j <= 6; j ++ ) {
            ans[cnt+j-n]++;
        }
        return;
    }
    for (int j = 1; j <= 6; j ++ ) {
        recursive(ans, i+1, n, cnt+j);
    }
}