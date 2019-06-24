#include <bits/stdc++.h>
using namespace std;

char firstMeet(string s) {
    int book[256] = {0};
    for (int i = 0; i < s.length(); i ++ ) {
        book[s[i]]++;
    }
    char ans;
    for (int i = 0; i < s.length(); i ++ ) {
        if (book[s[i]] == 1) {
            ans = s[i];
            break;
        }
    }
    return ans;
}