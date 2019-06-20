#include <bits/stdc++.h>
using namespace std;

bool cmp (int a, int b) {
    return a > b;
}

int main() {
    string s;
    cin >> s;
    int a[30] = {0};
    int num = 0;
    for (int i = 0; i < s.length(); i ++ ) {
        if (a[s[i]-'a'] == 0) num++;
        a[s[i]-'a']++;
    }
    sort(a, a+30, cmp);
    int ans = 0;
    bool flag = false;
    for (int i = 0; i < num; i ++ ) {
        if (a[i] >= 2) {
            a[i] = a[i]%2;
            flag = true;
        }
    }
    if (flag) {
        ans ++;
        for (int i = 0; i < num; i ++ ) {
            if (a[i] > 0) {
                a[i] = 0;
                break;
            }
        }
    } 
    for (int i = 0; i < num; i ++ ) {
        if (a[i] > 0) ans ++;
    }
    cout << ans << endl;
    return 0;
}