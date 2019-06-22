#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 找出数组中重复的数字
 *  Key: 将数组中的数字依次对号入座，如果某个数的位置被自己占了，说明找到了重复数字
 */

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans;
        for (int i = 0; i < nums.size(); i ++ ) {
            while (nums[i]-1 != i) {
                if (nums[nums[i]-1] == nums[i]) {
                    ans = nums[i];
                    break;
                } else {
                    swap(nums[i], nums[nums[i]-1]);
                }
            }
        }
        return ans;
    }
};