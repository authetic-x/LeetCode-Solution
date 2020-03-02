#include "stdio.h"
#include "stack"
using namespace std;

stack<int> st;
char str[110];
char ans[110];

int main() {
    while (scanf("%s", str) != EOF) {
        int i;
        for (i = 0; str[i] != 0; i ++ ) {
            if (str[i] == '(') {
                st.push(i);
                ans[i] = ' ';
            } else if (str[i] == ')') {
                if (!st.empty()) {
                    st.pop();
                    ans[i] = ' ';
                } else {
                    ans[i] = '?';
                }
            } else {
                ans[i] = ' ';
            }
        }
        while (!st.empty()) {
            ans[st.top()] = '$';
            st.pop();
        }
        ans[i] = 0;
        puts(str);
        puts(ans);
    }
    return 0;
}