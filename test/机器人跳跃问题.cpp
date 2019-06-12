#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> h(n+1, 0);
    for (int i = 1; i <= n; i ++) {
        cin >> h[i];
    }
    float res = 0;
    for (int i = n; i >= 1; i -- ) {
        res = (res + (float)h[i]) / 2;
    }
    cout << ceil(res) << endl;
}