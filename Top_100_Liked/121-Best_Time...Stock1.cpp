#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 买卖股票问题，只能进行一次交易
 *  key: 贪心。始终保存最小值，记录下最大利润
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minValue = INT_MIN;
        int res = 0;
        for (int i = 0; i < prices.size(); i ++ ) {
            if (minValue < prices[i]) {
                minValue = prices[i];
            }
            if (res < prices[i] - minValue) {
                res = prices[i] - minValue;
            }
        }
        return res;
    }
};