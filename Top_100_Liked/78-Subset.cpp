#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 给出一组不重复的数，返回所有的组合
 *  Key: 这类题目一般就是回溯或者迭代，这道题
 *       还可以用位运算做，目前只写了回溯写法，
 *       看来自己对于回溯的理解有很大的问题！
 */

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> sub;
        subset(nums, 0, sub, subs);
        return subs;
    }
    void subset(vector<int>& nums, int i, 
                vector<int>&sub, vector<vector<int>>& subs) {
        subs.push_back(sub);
        for (int j = i; j < nums.size(); j ++ ) {
            sub.push_back(nums[j]);
            subset(nums, j+1, sub, subs);
            sub.pop_back();
        }
    }
};

// 错误示范
class Solution_Wrong {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(res, tmp, nums, 0);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, vector<int> tmp, 
             vector<int> nums, int i) {
        if (i == nums.size()) res.push_back(tmp);
        tmp.push_back(nums[i]);
        dfs(res, tmp, nums, i+1);
        tmp.pop_back();
        dfs(res, tmp, nums, i+1);
    }
};