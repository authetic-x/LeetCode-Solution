#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> FindSequence(int s) {
    vector<vector<int>> ans;
    if (s <= 1) return ans;

    int small = 1, big = 2;
    int middle = (s+1) / 2;
    int curSum = 3;
    while (small < middle) {
        if (curSum == s) {
            ans.push_back({small, middle});
        }
        while (curSum > s && curSum < middle) {
            curSum -= small;
            small --;
            if (curSum == s) {
                ans.push_back({small, middle});
            }
        }
        big++;
        curSum += big;
    }
    return ans;
}