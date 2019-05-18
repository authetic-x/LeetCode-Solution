#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 给出一个数组，每个数组的值表示在当前下标能跳多远，
 *        判断是否可以跳到数组末尾
 *  Key: 有多种做法，回溯，DP，贪心，目前只实现了贪心，记录
 *       distance值，表示能跳到最远的下标，注意for循环条件
 */

// 贪心
class Solution1 {
public:
    bool canJump(vector<int>& nums) {
        int distance = 0;
        for (int i = 0; i < nums.size()-1 && i <= distance; i ++ ) {
            distance = max(distance, i + nums[i]);
        }
        if (distance >= nums.size()-1) return true;
        return false;
    }
};