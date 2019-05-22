#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 给出一串由左右括号组成的序列，找出其中合法的最大连续子序列
 *  Key: 做法有很多种，DP，
 */

// DP做法，未编译通过，报下标越界错误
class Solution1 {
public:
    int longestValidParentheses(string s) {
        int dp[s.length()+1];
        int res = 0;
        dp[0] = 0;
        for (int i = 1; i < s.length(); i ++ ) {
            if (s[i] == ')') {
                if (s[i-1] == '(') {
                    dp[i] = (i-2 >= 0 ? dp[i-2] :0) + 2;
                } else if (i-dp[i-1]-1 >= 0) {
                    if (dp[i-dp[i-1]-1] == '(') {
                        dp[i] = dp[i-1]+(i-dp[i-1]-2 >= 0 ? dp[i-dp[i-1]-2] : 0)
                            + 2;
                    }
                }
            } else {
                dp[i] = dp[i-1];
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

// 利用栈巧妙的写法，笔试中很难想出来
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        stack<int> st;
        st.push(-1);
        for (int i = 0; i < s.length(); i ++ ) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty) {
                    st.push(i);
                } else {
                    res = max(res, i-st.top());
                }
            }
        }
        return res;
    }
};

