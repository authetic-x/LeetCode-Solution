#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(const pair<int, int> &x, const pair<int, int> &y) {
        return x.second > y.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for (auto num : nums) {
            mp[num]++;
        }
        vector<pair<int, int>> v;
        for (auto m : mp) {
            v.push_back(make_pair(m.first, m.second));
        }
        sort(v.begin(), v.end(), cmp);
        for (auto m : v) {
            if (k == 0) break;
            ans.push_back(m.first);
            k--;
        }
        return ans;
    }
};