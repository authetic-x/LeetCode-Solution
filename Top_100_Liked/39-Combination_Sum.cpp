#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 给出一个不重复序列和一个目标数，找出所有总和等于目标数的组合数，每个数可以选取多次
 *  Key: 深度遍历！！！
 */

// 递归暴力枚举，运行超时
class Solution1 {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp;
        set<vector<int>> ans;
        combinate(candidates, ans, tmp, 0, 0, target);
        vector<vector<int>> res;
        auto ptr = ans.begin();
        for (; ptr != ans.end(); ptr ++ ) {
            res.push_back(*ptr);
        }
        return res;
    }
    void combinate(vector<int> can, set<vector<int>>& ans, vector<int> tmp, 
                    int sum, int i, int t) {
        if (sum > t) return;
        if (sum == t) {
            ans.insert(tmp);
            return;
        }
        tmp.push_back(can[i]);
        combinate(can, ans, tmp, sum+can[i], i, t);
        if (i < can.size()-1) {
            tmp.pop_back();
            combinate(can, ans, tmp, sum, i+1, t);
            tmp.push_back(can[i+1]);
            combinate(can, ans, tmp, sum+can[i+1], i+1, t);
        }
    }
};

// 深度遍历最优解，注意递归的写法
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        nums = candidates;
        this->target = target;
        dfs(0, 0);
        return res;
    }
private:
    vector<int> nums;
    int target;
    vector<vector<int>> res;
    vector<int> row;
    void dfs(int index, int sum) {
        if (index >= nums.size() || sum > target) return;
        if (sum == target) res.push_back(row);
        for (int i = index; i < nums.size(); i ++ ) {
            row.push_back(nums[i]);
            dfs(i, sum+nums[i]);
            row.pop_back();
        }
    }
};