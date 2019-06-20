#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int len = s.length();
    int ans = 0;
    int i = len/2-1, j = len-1;
    for (int k = 1; k < len/2; k ++ ) {
        j = j - 2;
        //int tmp = i;
        int p = 0, q = i;
        for (p = 0, q = i; p < i; p ++, q++ ) {
            if (s[p] != s[q]) break;
        }
        if (p == i) {
            ans = i*2;
            break;
        } else i--;
    }
    cout << ans << endl;
    return 0;
}