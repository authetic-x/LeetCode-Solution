#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 模拟简单的正则表达式
 *  Key: 用递归或者DP
 */

// 相当于分类讨论，有*和无*的情况分开处理
// 递归的效率很低，而且切分字符串对空间消耗也很大
class Solution1 {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        if (p.length() >= 2 && p[1] == '*') {
            return isMatch(s, p.substr(2)) || 
                    (!s.empty() && (s[0] == p[0] || p[0] == '.')
                     && isMatch(s.substr(1), p));
        }
        return !s.empty() && (s[0] == p[0] || p[0] == '.')
                && isMatch(s.substr(1), p.substr(1));
    }
};

class Solution2 {
public:
    bool isMatch(string s, string p) {
        return false;
    }
};