#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 在一个数组中找出有多少个连续一段的数，和为K
 *  Key: 先从头记录sum, 再用sum[j]-sum[i]遍历时间复杂度为O(n*n)
 *       可以使用map从头记录sum出现的次数，对每个sum求map[sum-k],
 *       时间复杂度为O(n)，空间复杂度为O(n)
 */

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0]++;
        int sum = 0;
        int ans = 0;
        for (auto num : nums) {
            sum += num;
            if (mp.find(sum-k) != mp.end()) {
                ans += mp[sum-k];
            }
            mp[sum]++;
        }
        return ans;
    }
};