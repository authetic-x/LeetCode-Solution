#include <bits/stdc++.h>
using namespace std;

/*
 * Info: 给出一个序列，找出最大长度不重复字符的子序列
 * Keys: 设置两个指针，用数组标记出现的字符，记住初始位置即可
 * 
 */


// 此版本为初始版本，测试出现数组越界问题
class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        // 标记出现的字符
        int flag[30] = {0};
        // 每个序列的起点，最大长度，当前最大长度
        int pre = 0, res = 0, coRes = 0;

        for (int i = 0; i < s.length(); i ++ ) {
            if (flag[s[i]-'a'] == 0) {
                flag[s[i]-'a'] = 1;
                coRes++;
            } else {
                if (coRes > res) res = coRes;
                int j = pre;
                while (s[j] != s[i]) {
                    flag[s[j]-'a'] = 0;
                    j++;
                    coRes--;
                }
                pre = j + 1;
            }
        }
        if (coRes > res) res = coRes;
        return res;
    }
};

// 最优解
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 标记出现的字符
        int book[256] = {0};
        // 每个序列的起点，当前指针位置，最大长度
        int i = 0, j = 0, maxlen = 0;
        int len = s.length();

        while (j < len) {
            if (book[s[j]] == 1) {
                maxlen = max(maxlen, j-i);
                while (s[i] != s[j]) {
                    book[s[i]] = 0;
                    i++;
                }
                i++;
            } else {
                book[s[j]] = 1;
            }
            j ++;
        }

        return max(maxlen, j-i);
    }
};