#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 给出一个数组，找出所有不重复的由三个不同数组成的和为0的序列
 *  Key: Two Pointers应用，先排序，然后从0开始遍历，相当于在剩余的
 *       序列里找出和为特定值的两个数，j,k移动的依据是三个数之和大于0还是小于0
 */

// 目前最优解
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int i = 0;
        while (i < len-2) {
            int j = i+1, k = len-1;
            while (j < k) {
                if (nums[j]+nums[k]+nums[i] == 0) {
                    vector<int> tmp = {nums[i], nums[j], nums[k]};
                    res.push_back(tmp);
                    j ++, k --;
                    while (j < k && nums[j] == nums[j-1]) j++;
                    while (j < k && nums[k] == nums[k+1]) k--;
                } else if (nums[j]+nums[k]+nums[i] < 0) {
                    j ++;
                } else {
                    k --;
                }
            }
            i ++;
            while (i < len-2 && nums[i]==nums[i-1]) i++;
        }
        return res;
    }
};