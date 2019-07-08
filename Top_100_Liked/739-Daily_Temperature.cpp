#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 给出一个很大的数组，找出每个数后面第一个比它大的数
 *  Key: 很显然暴力无法承受，设置next数组记录每个数出现的位置，从
 *       后向前开始遍历，题目设置数大小为30~100，时间复杂度为O(n*70)
 */

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ans(T.size(), 0);
        vector<int> next(101, INT_MAX);
        for (int i = T.size()-1; i >= 0; i -- ) {
            int warm_index = INT_MAX;
            for (int t = T[i]+1; t <= 100; t ++ ) {
                if (next[t] < warm_index) {
                    warm_index = next[t];
                }
            }
            if (warm_index < INT_MAX) {
                ans[i] = warm_index - i;
            }
            next[T[i]] = i;
        }
        return ans;
    }
};