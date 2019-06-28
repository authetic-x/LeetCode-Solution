#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 给出一系列硬币面值，和一个数额，求出最小所需硬币数
 *  Key: DP，初始化dp数组为amount+1，遍历求解
 */

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i ++ ) {
            for (auto coin : coins) {
                if (coin <= i) {
                    dp[i] = min(dp[i], dp[i-coin]+1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};