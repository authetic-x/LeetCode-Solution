#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 一个数组里只有0,1,2三个数，将它们排序
 *  Key: 题目提示可以先计算0,1,2的个数，然后重写数组，
 *       但有one pass, one constant array的方法，
 *       下面是抄袭聪明的网友的，原理就是保证low前面的
 *       数都是0，high后面的数都是2！
 */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size()-1;
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low++], nums[mid++]);
            } else if (nums[mid] == 1) {
                mid ++;
            } else {
                swap(nums[mid], nums[high--]);
            }
        }
    }
};