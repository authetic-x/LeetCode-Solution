#include <bits/stdc++.h>
using namespace std;

string ReverseWord(string s) {
    reverse(s.begin(), s.end());
    int i = 0, j = 0;
    while (j < s.length()) {
        while (s[j] != ' ') {
            j++;
        }
        reverse(s[i], s[j-1]);
        i = j+1, j++;
    }
    reverse(s[i], s[j-1]);
    return s;
}

string moveToEnd(string s, int k) {
    reverse(s[0], s[k-1]);
    reverse(s[k], s[s.length()-1]);
    reverse(s.begin(), s.end());
    return s;
}