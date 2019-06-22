#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 给出一个数组，返回一个数组，数组中每个数为除自身外其它所有数的乘积
 *  Key: 两个数组left,right记录，则left[i]*right[i]就是结果
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> res(size), left(size), right(size);
        left[0] = 1, right[size-1] = 1;
        for (int i = 1; i < size; i ++ ) {
            left[i] = left[i-1]*nums[i-1];
        }
        for (int j = size-2; j >= 0; j -- ) {
            right[j] = right[j+1]*nums[j+1];
        }
        for (int i = 0; i < size; i ++ ) {
            res[i] = left[i]*right[i];
        }
        return res;
    }
};