#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int book[128] = {0};
        for (int i = 0; i < J.length(); i ++ ) {
            book[J[i]] = 1;
        }
        int ans = 0;
        for (int i = 0; i < S.length(); i ++ ) {
            if (book[S[i]] == 1) ans++;
        }
        return ans;
    }
};