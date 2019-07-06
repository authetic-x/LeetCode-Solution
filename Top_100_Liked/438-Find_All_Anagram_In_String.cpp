#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 找出字符串s中所有下标，从该下标开始长度为p的字符串包含p中所有字符
 *  Key: 滑动窗口类型的题目，可直接维护两个map遍历比较，复杂度是O(n*m)
 */

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (s.length() < p.length()) return ans;
        vector<int> book(26, 0);
        for (int i = 0; i < p.length(); i ++ ) {
            book[p[i]-'a']++;
        }
        for (int i = 0; i < s.length()-p.length()+1; i ++ ) {
            vector<int> tmp(26, 0);
            for (int j = i; j < i+p.length(); j ++ ) {
                tmp[s[j]-'a']++;
            }
            if (book == tmp) ans.push_back(i);
        }
        return ans;
    }
};