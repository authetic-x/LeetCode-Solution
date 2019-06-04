#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 一个数组中有一个数只出现了一次，其余的都出现了两次，找出这个数
 *  Key: 如果要求线性时间复杂度且不用辅助存储空间，那么位运算绝对是个很好
 *       的选择，当然这么巧妙的方法任然是来自于聪明的网友，我只是个思想的
 *       搬运工！
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (auto num : nums) {
            res ^= num;
        }
        return res;
    }
};