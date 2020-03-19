#include "stdio.h"
#include "string"
#include "ctype.h"
using namespace std;

char str[101];

int main() {
    gets(str);
    string a = str;
    for (int i = 0; i < a.size(); i ++ ) {
        a[i] = tolower(a[i]);
    }
    while (gets(str)) {
        // b表示改为小写后的字符串，c为原串
        string b = str, c = b;
        for (int i = 0; i < b.size(); i ++ ) {
            b[i] = tolower(b[i]);
        }
        int t = b.find(a, 0);
        while (t != string::npos) {
            b.erase(t, a.size());
            c.erase(t, a.size());
            t = b.find(a, t);
        }
        t = c.find(' ', 0);
        while (t != string::npos) {
            c.erase(t, 1);
            t = c.find(' ', t);
        }
        printf("%s\n", c.c_str);
    }
    return 0;
}