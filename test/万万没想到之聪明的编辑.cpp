#include <stdio.h>
#include<iostream>
using namespace std;

string revise(string s) {
    int len = s.length();
    string ans = s.substr(0,2);
    int cur = 1, i = 2;
    
    while (i < len) {
        if ((s[i] == ans[cur] && ans[cur] == ans[cur-1])) {
            i ++;
            continue;
        }
        if (cur-2 >= 0) {
            if (s[i] == ans[cur] && ans[cur-1] == ans[cur-2]) {
                i ++;
                continue;
            }
        }
        ans += s[i++];
        cur++;
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) {
        string s;
        cin >> s;
        if (s.length() <= 3) {
            if (s.length() == 3 && (s[0] == s[1] && s[1] == s[2])) {
                s = s.substr(0, 2);
            }
            cout << s << endl;
            continue;
        }
        cout << revise(s) << endl;
    }
    return 0;
}