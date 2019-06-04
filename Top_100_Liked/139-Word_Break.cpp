#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 模拟分词，给出一个“词典”，里面的词可以重复使用，求能不能构成给定的字符串
 *  Key: 动态规划。
 */

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for (auto word : wordDict) {
            dict.insert(word);
        }
        vector<bool> dp(s.length()+1, false);
        dp[0] = true;
        for (int i = 1; i <= s.length(); i ++ ) {
            for (int j = i-1; j >= 0; j -- ) {
                if (dp[j]) {
                    string word = s.substr(j, i-j);
                    if (dict.find(word) != dict.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.length()];
    }
};