#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    int dp[10000][10000];
    for (int i = 3; i <= 9999; i += 2) {
        for (int j = 3; j <= 9999; i += 2) {
            
        }
    }
    while (t--) {
        int n;
        cin >> n;
        if (n <= 2) cout << -1 << endl;
        else {
            int ceil;
            if (n%2 == 0) ceil = n/2-1;
            else ceil = n;
            int i = 3, j = 3;
            int cnt = 3;
            while (cnt != n && j <= ceil) {
                if (cnt < n) {
                    j += 2;
                    cnt += j; 
                } else {
                    cnt -= i;
                    i += 2;
                }
            }
            if (cnt == n) cout << (i-1)/2 << endl;
        }
    }
    return 0;
}