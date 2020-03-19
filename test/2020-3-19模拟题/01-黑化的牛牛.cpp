#include "stdio.h"
#include "string"
#include "set"
using namespace std;

set<string> st;

int main() {
    char str[51];
    while (gets(str)) {
        string a = str, b = a;
        for (int i = 0; i < a.size(); i ++ ) {
            b.erase(i, 1);
            if (st.find(b) == st.end()) {
                st.insert(b);
            }
            b = a;
        }
        printf("%d\n", st.size());
    }
    return 0;
}