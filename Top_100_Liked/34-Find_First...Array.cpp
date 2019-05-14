#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 给出一个升序数组，返回target的起始位置和终止位置
 *  Key: 二分查找
 */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while (l <= r) {
            int mid = (l+r)/2;
            if (nums[mid] == target) {
                int i = mid, j = mid;
                while (i >= 0 && nums[i] == target) i--;
                while (j < nums.size() && nums[j] == target) j++;
                return {i+1, j-1};
            }
            if (nums[mid] > target) r = mid-1;
            else l = mid+1;
        }
        return {-1,-1};
    }
}; 