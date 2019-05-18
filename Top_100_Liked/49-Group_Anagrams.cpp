#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 给出一个字符串数组，将其中含有相同字母组成的字符串分组
 *  Key: 给字符串排序然后用map存储，C++的新特性写起来还是很舒服的
 */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (auto s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto m : mp) { 
            //vector<string> tmp(m.second.begin(), m.second.end());
            ans.push_back(m.second);
        }
        return ans;
    }
};