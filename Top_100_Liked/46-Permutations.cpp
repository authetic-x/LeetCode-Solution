#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 给出一个序列，返回它的全排列
 *  Key: 先排序，调用库函数 next_permutation
 */

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        do {
            res.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return res;
    }
};