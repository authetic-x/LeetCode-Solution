#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 给出两个字符串，返回第一个字符串中能够包含第二个字符串所有字母的
 *        最短子串
 *  Key: 滑动窗口，设置两个指针left, right，从0开始，当left与right间的
 *       子串还不包含第二个字符串所有字符时，right一直向后移动，一旦包含了
 *       所有字符，left向前移动，并记录子串长度，依次进行以上判断即可！
 *       关键是如何判断是否包含所有字符。
 */

// 聪明的网友用数组实现的一种方式，还有bug
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() == 0 || t.size() == 0) return "";
        vector<int> remains(128, 0);
        for (int i = 0; i < t.size(); i ++ ) {
            remains[t[i]]++;
        }
        // st 为最小子串开始的位置
        int min = INT_MAX, st = 0, left = 0, right = 0;
        int required = t.size();
        while(right < s.size() && left <= right) {
            if (required) {
                remains[s[right]]--;
                if (remains[s[right]] >= 0) {
                    required--;
                }
                right ++;
            } else {
                if (right - left < min) {
                    min = right - left;
                    st = left;
                }
                remains[s[left]]++;
                if (remains[s[left]] > 0) required++;
                left++;
            }
        }
        return min == INT_MAX ? "" : s.substr(st, min);
    }
};