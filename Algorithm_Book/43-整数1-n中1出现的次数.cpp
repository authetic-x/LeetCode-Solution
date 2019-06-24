#include <bits/stdc++.h>
using namespace std;

/*
 *  以21345为例：
 *  分为两部分：1~1345，1346~21345
 *  对于第二部分，最高位的1出现在10000~19999，共10000次
 *  (如果将2改为1，将只出现1346次)，
 *  其它位的1为 2*4*10^3
 *  对于第一部分，可用相同的方式，递归进行
 */

int numOfOne(int n) {
    string s = to_string(n);
    return Core(s);
}

int Core(string s) {
    int len = s.length();
    if (len == 1 && s[0] == '0') return 0;
    if (len == 1) return 1;
    
    int numOfFirst;
    if (s[0] > '1') numOfFirst = (int)pow(10, len-1);
    else if (s[0] == '1') numOfFirst = stoi(s.substr(1, len-1)) + 1;
    
    int numOfOther = (s[0]-'0')*(len-1)*pow(10, len-2);
    int numOfRecur = Core(s.substr(1, len-1));
    return numOfFirst + numOfOther + numOfRecur;
}