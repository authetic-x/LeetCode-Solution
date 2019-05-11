#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 给出一个数组，每个数组值代表墙的高度，返回能容纳最多水的区间大小
 *  Key: Two Pointers应用，移动i, j的依据在于如何扩大当前最大值，即移动
 *       高度小的那一方
 */

// 最优解
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int i = 0, j = height.size()-1;
        while (i < j) {
            res = max(res, (j-i)*min(height[i], height[j]));
            if (height[i] < height[j]) i++;
            else j--;
        }
        return res;
    }
};