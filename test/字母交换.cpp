#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int m;
    cin >> m;
    int num_char = 0;
    int character[128] = {0};
    for (int i = 0; i < s.length(); i ++ ) {
        if (character[s[i]] == 0) {
            character[s[i]] = 1;
            num_char++;
        }
    }
    for (int i = 0; i < 128; i ++ ) character[i] = 0;
    char c = '-';
    int len = 0;
    char curC = '-';
    int curLen = 0;
    for (int i = 0; i < s.length(); i ++ ) {
        if ()
        if (s[i] != curC) {
            curLen = 0;
            curC = s[i];
        } else {
            curLen ++;
            if (len < curLen) {
                c = curC;
                len = curLen;
            }
        }
    }
}