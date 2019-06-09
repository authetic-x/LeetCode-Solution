#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 找出数组中出现次数超过数组长度一半的数字
 *  Key: 设置变量记录数字出现的次数，最后存活的那个数字就是结果
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1, flag;
        flag = nums[0];
        for (int i = 1; i < nums.size(); i ++ ) {
            if (flag == nums[i]) count ++;
            else if (count != 0) count --;
            else {
                flag = nums[i];
                count++;
            }
        }
        return flag;
    }
};