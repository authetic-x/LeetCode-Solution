#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 排序数组的某个连续空间将数组变为升序，求区间长度
 *  Key: 其实就是求左边需要移动最左边的点和最右边的点
 */

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> snums(nums.size());
        for (int i = 0; i < nums.size(); i ++ ) {
            snums[i] = nums[i];
        }
        sort(snums.begin(), snums.end());
        int l = nums.size(), r = 0;
        for (int i = 0; i < nums.size(); i ++ ) {
            if (nums[i] != snums[i]) {
                l = min(l, i);
                r = max(r, i);
            }
        }
        return r-l <= 0 ? 0 : r-l+1;
    }
};

// 暴力超时
class Solution1 {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int l = nums.size(), r = 0;
        for (int i = 0; i < nums.size()-1; i ++ ) {
            for (int j = i+1; j < nums.size(); j ++ ) {
                if (nums[j] < nums[i]) {
                    l = min(i, l);
                    r = max(j, r);
                }
            }
        }
        return r-l <= 0 ? 0 : r-l+1;
    }
};