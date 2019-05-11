#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 生成括号。给出上限，返回所有不同的括号组合
 *  Key: 简单回溯问题，相当于选左括号还是右括号，关键是
 *       当已选左括号数大于已选右括号数时，才能选右括号
 */


// Not the best
// Mask
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur = "";
        backtrack(res, cur, 0, 0, n);
        return res;
    }

    void backtrack(vector<string>&res, string cur, int open, 
                    int close, int max) {
        if (cur.length() == max*2) {
            res.push_back(cur);
            return;
        }
        if (open < max) {
            backtrack(res, cur+"(", open+1, close, max);
        }
        if (close < open) {
            backtrack(res, cur+")", open, close+1, max);
        }
    }
};