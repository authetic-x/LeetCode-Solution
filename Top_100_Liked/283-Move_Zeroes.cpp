#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 将数组中的零全部移到数组的末尾并保证其它元素的相对顺序
 *  Key: 设置两个指针i,j，如果没有0，i,j会一起移动，否则i会停在0的位置，
 *       j一直向前移动知道找到非零位置可与i交换
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0, j = 0; j < nums.size(); j ++ ) {
            if (nums[j] != 0) {
                swap(nums[i++], nums[j]);
            }
        }
    }
};