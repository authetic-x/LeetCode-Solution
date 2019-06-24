#include <bits/stdc++.h>
using namespace std;

int MaxLengthOfSubstr(string s) {
    int book[128] = {0};
    int ans = 0;
    int i = 0, j = 0;
    for (; i < s.length(); i ++ ) {
        if (book[s[i]] == 0) {
            book[s[i]] == 1;
        } else {
            ans = max(ans, i-j);
            while (s[j] != s[i]) {
                book[s[j]] = 0;
                j ++;
            }
            j++;
        }
    }
    return max(ans, i-j);
}