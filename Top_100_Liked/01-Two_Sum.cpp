#include <bits/stdc++.h>
using namespace std;

/*
 *   Description: 给出一个数组，和一个目标值，返回数组中两个数之和
 *   等于目标值的对应下标
 *   Key: 用unordered_map存储，遍历数组。
 *   Note: unorder_map为无序存储的map，效率更高
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i ++ ) {
            auto p = mp.find(target-nums[i]);
            if (p != mp.end()) {
                return {p->second, i};
            }
            mp[nums[i]] = i;
        }
        // 其实不需要这行语句，但leetcode编译通不过
        return {0,1};
    }
};