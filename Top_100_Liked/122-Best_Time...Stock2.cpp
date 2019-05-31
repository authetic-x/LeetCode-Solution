#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 买卖股票问题，可进行多次交易
 *  Key: 还是贪心。把所有上升的曲线加起来即可！
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int res = 0;
        int valley = prices[0], peak = prices[0];
        int i = 0;
        while (i < prices.size()-1) {
            while (i < prices.size()-1 && prices[i] >= prices[i+1]) {
                i ++;
            }
            valley = prices[i];
            while (i < prices.size()-1 && prices[i] <= prices[i+1]) {
                i ++;
            }
            peak = prices[i];
            res += peak - valley;
        }
        return res;
    }
};