#include <bits/stdc++.h>
using namespace std;

vector<string> permutation(string s) {
    vector<string> ans;
    permutate(ans, s, 0);
    return ans;
}

void permutate(vector<string> &ans, string s, int i) {
    if (i == s.length()) {
        ans.push_back(s);
    }
    for (int j = i; j < s.length(); j ++ ) {
        char tmp = s[i];
        s[i] = s[j];
        s[j] =tmp;
        permutate(ans, s, i+1);
        s[j] = s[i];
        s[i] = tmp;
    }
}