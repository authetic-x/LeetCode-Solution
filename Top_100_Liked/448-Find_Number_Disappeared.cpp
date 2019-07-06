#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 长度为n的数组，数字范围为1-n，找出一到n中没出现的数
 *  Key: 与找重复数方法一样，将数组中的数发到下标与其值一致的位置
 */

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i ++ ) {
            while (nums[i] != i+1) {
                if (nums[nums[i]-1] != nums[i]) {
                    swap(nums[nums[i]-1], nums[i]);
                } else break;
            }
        }
        for (int i = 0; i < nums.size(); i ++ ) {
            if (nums[i] != i+1) ans.push_back(i+1);
        }
        return ans;
    }
};