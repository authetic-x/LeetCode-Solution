#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 给出一个elevation map, 每个数代表高度，算出其积水容量
 *  Key: DP，跟普通动规不同，这道题做法更巧妙，先从左边遍历把坑都
 *       填起来，再从右边遍历把坑填起来，再从头遍历取填坑最小值减去
 *       当前高度，将它们加起来就是结果！
 */

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;
        int res = 0;
        int size = height.size();
        vector<int> left_max(size), right_max(size);
        left_max[0] = height[0];
        for (int i = 1; i < size; i ++ ) {
            left_max[i] = max(left_max[i-1], height[i]);
        }
        right_max[size-1] = height[size-1];
        for (int i = size-2; i >= 0; i -- ) {
            right_max[i] = max(right_max[i+1], height[i]);
        }
        for (int i = 1; i < size-1; i ++ ) {
            res += min(left_max[i], right_max[i]) - height[i]; 
        }
        return res;
    }
};