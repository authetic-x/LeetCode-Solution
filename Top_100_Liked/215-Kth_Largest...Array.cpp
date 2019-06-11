#include <bits/stdc++.h>
using namespace std;

/*
    Info: 找出一个无序数组中第K大的元素，指按数组排序后的第K个元素
    Key: 可以使用一些内置函数，例如nth_element，或者partial_sort
 */

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin()+k-1, nums.end(), greater<int>());
        return nums[k-1];
    }
};