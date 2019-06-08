#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 在一个数组中，找出一段乘积最大的连续子数组
 *  Key: 贪心问题。搞不清楚，搞晕了，下面是柳婼同学的答案
 */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int res = nums[0], maxValue = nums[0], minValue = nums[0];
        for (int i = 1; i < nums.size(); i ++ ) {
            int tempMax = max(nums[i], maxValue * nums[i]);
            int tempMin = min(nums[i], maxValue * nums[i]);
            maxValue = max(tempMax, minValue * nums[i]);
            minValue = min(tempMin, minValue * nums[i]);
            res = max(res, maxValue);
        }
        return res;
    }
};