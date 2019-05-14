#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 旋转数组，低配版
 *  Key: 二分查找，关键是先确定当前查找范围是否是旋转数组
 *       且位于旋转数组的那一侧，然后再去缩小查找范围
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while (l <= r) {
            int mid = (l+r)/2;
            if (nums[mid] == target) return mid;
            if (nums[mid] > nums[r]) {
                if (target >= nums[l] && target < nums[mid]) {
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            } else if (nums[mid] < nums[l]) {
                if (target <= nums[r] && target > nums[mid]) {
                    l = mid+1;
                } else {
                    r = mid-1;
                }
            } else {
                if (nums[mid] > target) r = mid-1;
                else l = mid+1;
            }
        }
        return -1;
    }
};