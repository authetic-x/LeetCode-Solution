#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 给出一个数组，判断该数组是否可以划分为和相等的两部分
 *  Key: 这种和问题应该是典型的01knapsack了，解决dp问题就两步：
 *       1. 找到问题中存在的子问题
 *       2. 弄清dp数组的意义
 *       学会转换问题，像这道题实际上就是找一个target
 */

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto num : nums) sum += num;
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for (auto num : nums) {
            for (int i = target; i >= num; i -- ) {
                dp[i] = dp[i] || dp[i-num];
            }
        }
        return dp[target];
    }
};