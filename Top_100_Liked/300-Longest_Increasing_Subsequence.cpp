#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 找到数组中最长不连续升序序列
 *  Key: dp
 */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> dp(nums.size(), 1);
        int ans = 1;
        for (int i = 1; i < nums.size(); i ++ ) {
            for (int j = 0; j < i; j ++ ) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};