#include "stdio.h"
#include "stack"
using namespace std;

char str[210];
// 存放结果值
stack<double> st1;
// 存放符号
stack<char> st2;

int main() {
    while (scanf("%s", str) != EOF && str[0] != 0) {
        for (int i = 0; str[i] != 0; i ++ ) {
            if (str[i] >= '0' && str[i] <= '9') {
                st1.push(double(str[i] - '0'));
            } else {
                if (st2.empty()) {
                    st2.push(str[i]);
                } else if (str[i] == '*' || str[i] == '/') {
                    
                }
            }
        }
    }
}