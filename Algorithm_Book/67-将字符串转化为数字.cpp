#include <bits/stdc++.h>
using namespace std;

long long strconv(string str) {
    if (str == "") return -1;
    bool minus = true;
    if (str.length() == 1 && (str[0] < '0' || str[0] > '9')) {
        return -1;
    }
    for (int i = 1; i < str.length(); i ++ ) {
        if (str[i] < '0' || str[i] > '9') return -1;
    }
    if (str[0] == '+') str = str.substr(1, str.length()-1);
    if (str[0] == '-') {
        minus = false;
        str = str.substr(1, str.length()-1);
    }

    long long num = 0;
    for (int i = 0; i < str.length(); i ++ ) {
        num = num*10 + (str[i]-'0');
    }
    if ((minus && num > (signed int)0x7fffffff) || (!minus && num < (signed int)0x80000000)) {
        return -1;
    }
    if (!minus) num = -num;
    return num;
}