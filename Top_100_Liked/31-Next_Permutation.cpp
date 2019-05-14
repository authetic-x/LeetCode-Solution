#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 给出一个序列，要求将序列变为“下一个”更大的序列，如果已经最大，就回到最小
 *  Key: 技巧题。先思考如何才能变大，降序序列已经最大，可以从末尾的升序序列一直遍历，
 *       找到一个降序的数i, 将i与后面的升序序列中第一个比它大的数交换。此时原序列
 *       变大了，但不是最终结果，注意到i后面的序列仍旧是一段升序序列，只需要将它们
 *       翻转一下便可得到最终结果。
 */

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-2;
        while (i >= 0 && nums[i] >= nums[i+1]) i--;
        if (i >= 0) {
            int j = nums.size()-1;
            while (nums[j] <= nums[i]) j--;
            swap(nums, i, j);
            reverse(nums, i+1);
        } else {
            reverse(nums, i+1);
        }
    }
    void reverse(vector<int>& nums, int st) {
        int ed = nums.size() - 1;
        while (st < ed) {
            swap(nums, st, ed);
            st++, ed--;
        }
    }
    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};