#include "stdio.h"
#include "stack"
using namespace std;

/*
    基本方法是用两个栈：一个栈保存运算符，一个栈保存数字
    当栈顶运算符优先级更高时，将其取出来计算，否则将优先级
    更高的运算符入栈
*/

stack<double> in;
stack<int> op;

char str[220];
// mat[i][j]为1时表示i优先级大于j
// 第一个为人工优先级最低运算符
int mat[][5] = {
    1, 0, 0, 0, 0,
    1, 0, 0, 0, 0,
    1, 0, 0, 0, 0,
    1, 1, 1, 0, 0,
    1, 1, 1, 0, 0
};

// reto为true表示当前返回的是运算符，且retn为运算符的编号
void getOP(bool &reto, int &retn, int &i) {
    if (i == 0 && op.empty()) {
        reto = true;
        retn = 0;
        return;
    }
    if (str[i] == 0) {
        reto = true;
        retn = 0;
        return;
    }

    if (str[i] >= '0' && str[i] <= '9') {
        reto = false;
    } else {
        reto = true;
        if (str[i] == '+') {
            retn = 1;
        } else if (str[i] == '-') {
            retn = 2;
        } else if (str[i] == '*') {
            retn = 3;
        } else if (str[i] == '/') {
            retn = 4;
        }
        i += 2;
        return;
    }
    retn = 0;
    for (; str[i] != ' ' && str[i] != 0; i ++ ) {
        retn *= 10;
        retn += str[i] - '0';
    }
    if (str[i] == ' ') i++;
}

int main() {
    while (gets(str)) {
        if (str[0] == '0' && str[1] == 0) break;
        bool retop;
        int retnum, idx = 0;
        while (!op.empty()) op.pop();
        while (!in.empty()) in.pop();
        while (true) {
            getOP(retop, retnum, idx);
            if (!retop) {
                in.push((double)retnum);
            } else {
                double tmp;
                if (op.empty() || mat[retnum][op.top()] == 1) {
                    op.push(retnum);
                } else {
                    while(mat[retnum][op.top()] == 0) {
                        int ret = op.top();
                        op.pop();
                        double b = in.top();
                        in.pop();
                        double a = in.top();
                        in.pop();
                        if (ret == 1) tmp = a + b;
                        else if (ret == 2) tmp = a - b;
                        else if (ret == 3) tmp = a * b;
                        else tmp = a / b;
                        in.push(tmp);
                    }
                    op.push(retnum);
                }
            }
            if (op.size() == 2 && op.top() == 0) break;
        }
        printf(".2lf\n", in.top());
    }
    return 0;
}