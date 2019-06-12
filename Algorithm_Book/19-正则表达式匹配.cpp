#include <bits/stdc++.h>
using namespace std;

bool match(char *text, char *pattern) {
    if (text == nullptr || pattern == nullptr) return false;
    return matchCore(text, pattern);
}

bool matchCore(char *text, char *pattern) {
    if (*text == '\0' && *pattern == '\0') return true;
    if (*text != '\0' && *pattern == '\0') return false;
    if (*(pattern+1) == '*') {
        if (*pattern == *text || *pattern == '.') {
            return matchCore(text+1, pattern) 
                    || matchCore(text, pattern+2)
                    || matchCore(text+1, pattern+2);
        } else {
            return matchCore(text, pattern+2);
        }
    }
    if (*pattern == *text) {
        return matchCore(text+1, pattern+1);
    }
    return false;
}