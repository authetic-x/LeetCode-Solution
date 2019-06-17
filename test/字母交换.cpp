#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 可以巧妙的转换为求最长连续序列问题，遍历字符串中的每个字母，
 *        每次遍历中，记录字母的位置，然后用dp求出在不超过限制条件下
 *        可组成的最长连续序列
 */

int main() {
    string s;
    cin >> s;
    int m;
    cin >> m;
    int ans = 0;
    for (char c = 'a'; c <= 'z'; c ++ ) {
        vector<int> pos;
        for (int i = 0; i < s.length(); i ++ ) {
            if (c == s[i]) {
                pos.push_back(i);
            }
        }
        int len = pos.size();
        if (len < 2) continue;
        int tmpAns = 0;
        vector<vector<int>> dp(len, vector<int>(len, 0));
        for (int L = 2; L <= len; L ++ ) {
            for (int i = 0; i+L-1 < len; i ++ ) {
                int j = i+L-1;
                if (i+1 <= j-1) {
                    dp[i][j] = dp[i+1][j-1]+(pos[i+1]-pos[i]-1) + (pos[j]-pos[j-1]-1);
                } else {
                    dp[i][j] = pos[j]-pos[i]-1;
                }
                if (dp[i][j] <= m) {
                    tmpAns = L;
                }
            }
        }
        ans = max(ans, tmpAns);
    }
    cout << ans << endl;
    return 0;
}