#include <bits/stdc++.h>
using namespace std;

/*
 * Info: 返回最长回文字符串
 * Keys: 分奇字符串和偶字符串向两边搜索
 * Note: substr(index, len)函数返回从index开始，
 *       长度为len的子字符串
 */

// 不是最优解，内存占用太大；
// 奇怪的是，用以下写法内存占用任超过100M
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        int st = 0, maxlen = 1;
        for (int i = 0; i < len-1; i ++ ) {
            int len1 = midToSide(s, i, i);
            int len2 = midToSide(s, i, i+1);
            int len = max(len1, len2);
            if (len > maxlen) {
                maxlen = len;
                st = i - (len-1)/2;
            }
        }
        return s.substr(st, maxlen);
    }
    
    int midToSide(string s, int l, int r) {
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            l--;
            r++;
        }
        return r-l-1;
    }
};