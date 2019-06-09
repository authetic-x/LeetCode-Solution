#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 有一连串房子，连着抢劫会触发警报，在不触发警报的情况最多可以抢多少钱
 *  Key: 本以为是贪心，死活想不出来，下面是简单的DP解法
 */

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = nums[0] > nums[1] ? nums[0] : nums[1];
        for (int i = 2; i < n; i ++ ) {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
};