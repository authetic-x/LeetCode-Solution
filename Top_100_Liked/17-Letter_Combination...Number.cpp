#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 给出一串数字字符串，返回所有可能出现在电话按键上的字母组合
 *  Key: 回溯或者迭代，这类问题本身不难，需要练习
 */

// iterative solution
// Copy from LIUCHUO, not your solution!!
// Need practice
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.length() == 0) return res;
        res.push_back("");
        vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (int i = 0; i < digits.length(); i ++ ) {
            vector<string> tmp;
            string s = v[digits[i]-'0'];
            for (int j = 0; j < s.length(); j ++ ) {
                for (int k = 0; k < res.size(); k ++ ) {
                    tmp.push_back(res[k]+s[j]);
                }
            }
            res = tmp;
        }
        return res;
    }
};


// to do, backtracking solution
class Solution1 {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.length() == 0) return res;
        combination("", digits, 0, res);
        return res;
    }
private:
    vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void combination(string tmp, string &digits, int offset, 
                        vector<string> &res) {
        if (offset >= digits.length()) {
            res.push_back(tmp);
            return;
        }
        int index = digits[offset]-'0';
        for (int i = 0; i < v[index].size(); i ++ ) {
            combination(tmp+v[index][i], digits, offset+1, res);
        }
    }
};