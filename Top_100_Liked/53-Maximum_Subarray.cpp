#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 给出一个序列，求连续子序列的最大值
 *  Key: 检验tmp的正负，每一步用res记录，结果取最大值
 */ 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int res = nums[0], tmp = nums[0];
        for (int i = 1; i < nums.size(); i ++ ) {
            if (tmp >= 0) {
                tmp += nums[i];
            } else {
                tmp = nums[i];
            }
            res = max(res, tmp);
        }
        return res;
    }
};