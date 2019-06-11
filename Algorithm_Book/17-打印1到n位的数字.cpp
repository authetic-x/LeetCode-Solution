#include <bits/stdc++.h>
using namespace std;

void PrintN(int n) {
    if (n < 0) return;
    char str[n+1];
    fill(str, str+n, '0');
    while (!Increcement(str, n-1)) {
        PrintStr(str, n);
    }
}

// 这里的n指字符数组下标
bool Increcement(char *str, int n) {
    if (str[n] == '9' && n == 0) return false;
    int flag = true;
    if (str[n] == '9') {
        str[n] = '0';
        flag = Increcement(str, n-1);
    } else {
        int num = str[n] - '0' + 1;
        str[n] = '0' + num;
    }
    return flag;
}
// 这里的n指n位数字
void PrintStr(char* str, int n) {
    int i = 0;
    for (; i < n-1; i ++) {
        if (str[i] != '0') break;
    }
    for (; i < n; i ++ ) {
        printf("%c", str[i]);
    }
    printf("\n");
}