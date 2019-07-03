#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 将类似于"3[a2[c]]"编码的字符串转化解码为原始string
 *  Key: 基础的递归调用和string操作，弄清递归函数的功能
 */

class Solution {
public:
    string decodeString(string s) {
        if (s.length() == 0) return "";
        int k = s.find('[');
        if (k == s.npos) return s;
        int cnt = 1;
        int i = k+1;
        for (i = k+1; i < s.length(); i ++ ) {
            if (s[i] == '[') cnt++;
            if (s[i] == ']') {
                cnt--;
                if (cnt == 0) break;
            }
        }
        string middle = decodeString(s.substr(k+1, i-k-1));
        string last = decodeString(s.substr(i+1));
        i = k-1;
        while (i >= 0 && (s[i] >= '0' && s[i] <= '9')) {
            i--;
        }
        string ans = s.substr(0, i+1);
        cnt = stoi(s.substr(i+1, k-i-1));
        while (cnt--) {
            ans += middle;
        }
        ans += last;
        return ans;
    }
};