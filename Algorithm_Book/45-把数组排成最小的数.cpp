#include <bits/stdc++.h>
using namespace std;

/*
 *  把数组中的数字转化为字符串，返回将字符串排序拼接即可
 */

bool cmp(string a, string b) {
    string s1 = a+b, s2 = b+a;
    if (s1 < s2) {
        return true;
    } else return false;
}

void PrintMinNum(vector<int> v) {
    vector<string> s(v.size());
    for (auto num : v) {
        s.push_back(to_string(num));
    }
    sort(s.begin(), s.end(), cmp);
    string ans = "";
    for (auto str : s) {
        ans += str;
    }
    cout << ans << endl;
}